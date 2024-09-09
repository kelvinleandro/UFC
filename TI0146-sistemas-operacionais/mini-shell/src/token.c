#include "token.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

tokenlist_t* tokenlist_create(size_t n){
    tokenlist_t* tkl = malloc(sizeof(tokenlist_t));
    tkl->tokens = malloc(sizeof(token_t)*n);
    tkl->len = 0;
    tkl->capacity = n;
    return tkl;
}

token_t* token_create(tokenvalue_t val, tokentype_t type){
    token_t* tk = malloc(sizeof(token_t));
    tk->type = type;
    tk->value = val;
    return tk;
}

void tokenlist_realloc_if_needed(tokenlist_t* tkl){
    if(TOKENLIST_LEN(tkl) ==  TOKENLIST_CAPACITY(tkl)) {
        void* newptr = realloc(tkl->tokens, sizeof(token_t)*TOKENLIST_CAPACITY(tkl)*2);
        if (newptr == NULL) {
            perror("Something went wrong on realloc for tokenlist");
            exit(1);
        }
        tkl->tokens = newptr;
    }
}

void tokenlist_append(tokenlist_t* tkl, tokenvalue_t val, tokentype_t type){
    tokenlist_realloc_if_needed(tkl);
    tkl->tokens[TOKENLIST_LEN(tkl)++] = token_create(val, type);
}

const char* const operators = "=;>|";
const char* const delimiters = " \n\r";

void tokenlist_print(tokenlist_t* tkl) {
    for(int i = 0; i < tkl->len; i++) {
        token_t* tk = tkl->tokens[i];
        switch (tk->type) {
            case TOKEN_COMMAND:
                printf("COMMAND [%s]", tk->value.str);
                break;
            case TOKEN_ARGS:
                printf("ARGS [%s]", tk->value.str);
                break;
            case TOKEN_STRING:
                printf("STR [%s]", tk->value.str);
                break;
            case TOKEN_OPERATOR:
                printf("OP [%c]", tk->value.operator);
                break;
        }
        printf(" -> ");
    }
    puts("");
}

tokenlist_t* tokenize(char* src) {
    int i = 0;
    char* start = src;
    tokenlist_t* tkl = tokenlist_create(20);
    bool is_command = true;
    /*bool instr = false;*/

    for(
        ;
        src[i] != '\0';
        i++){

        char* operator = NULL;
        if(
            (operator = strchr(operators, src[i])) != NULL || 
            strchr(delimiters, src[i]) != NULL
        ) {
            src[i] = '\0';

            if(strlen(start) > 0) {
                tokenvalue_t tkstr;

                tkstr.str = start;

                tokentype_t tktp; 

                if(is_command) {
                    tktp = TOKEN_COMMAND;
                    is_command = false;
                }else {
                    tktp = TOKEN_ARGS;
                }


                tokenlist_append(tkl, tkstr, tktp);

            }

            if(operator != NULL) {

                tokenvalue_t tkop;
                tkop.operator = *operator;
                tokenlist_append(tkl, tkop, TOKEN_OPERATOR);
                is_command = true;

            }                      
            
            start = src + i + 1;
        }
    }

    if(strlen(start) > 0) {
        tokenvalue_t tkstr;

        tkstr.str = start;

        tokentype_t tktp; 

        if(is_command) {
            tktp = TOKEN_COMMAND;
            is_command = false;
        }else {
            tktp = TOKEN_ARGS;
        }


        tokenlist_append(tkl, tkstr, tktp);
    }
    return tkl;
}
