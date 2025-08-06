
#include "str_utils.h"
#include <string.h>

void reverse_string(char *str) {
    if (str == NULL) return;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int string_length(const char *str) {
    if (str == NULL) return 0;
    return strlen(str);
}

int count_char(const char *str, char c) {
    if (str == NULL) return 0;
    int count = 0;
    while (*str) {
        if (*str == c) count++;
        str++;
    }
    return count;
}
