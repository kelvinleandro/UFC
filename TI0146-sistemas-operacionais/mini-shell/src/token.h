#ifndef __TOKEN__
#define __TOKEN__
#include <stdlib.h>
#define TOKENLIST_LEN(tkl) tkl->len
#define TOKENLIST_CAPACITY(tkl) tkl->capacity

typedef enum {
    TOKEN_COMMAND,
    TOKEN_ARGS,
    TOKEN_STRING,
    TOKEN_OPERATOR
} tokentype_t;

typedef union {
    char operator;
    char* str;
} tokenvalue_t;

typedef struct {
    tokentype_t type;
    tokenvalue_t value;
} token_t;

typedef struct {
    token_t** tokens;
    size_t len;
    size_t capacity;
}tokenlist_t;


tokenlist_t* tokenlist_create(size_t n);
token_t* token_create(tokenvalue_t val, tokentype_t type);
void tokenlist_append(tokenlist_t* tokenlist, tokenvalue_t val, tokentype_t type);
tokenlist_t* tokenize(char* src);
void tokenlist_print(tokenlist_t* tkl);

#endif
