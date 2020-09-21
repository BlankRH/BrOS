#include "string.h"
#include "types.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len) {
    for (; len != 0; len--) {
        *dest++ = *src++;
    }
}

inline void memset(void *dest, uint8_t val, uint32_t len) {
    uint8_t *dst = (uint8_t *)dest;
    
    for ( ; len != 0; len--) {
        *dst++ = val;
    }
}

inline void bzero(void *dest, uint32_t len) {
    memset(dest, 0, len);

inline int strcmp(const char *str1, const char *str2) {
    for ( ; len != 0; len--) {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 < *str2) {
            return -1;
        }
    }
    return 0;
}

char *strcpy(char *dest, const char *src) {
    if(dest == NULL || src == NULL)
        return NULL;
    char *ret = dest;
    while((*dest++ = *src++) != '\0')
        ;
    return ret;
}

char *strcat(char *dest, const char *src) {
    char *ret = dest;
    while (*dest++ != '\0')
        ;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';

    return ret;
}

int strlen(const char *src) {
    uint32_t len = 0;
    while (*src++ != '\0') {
        len++;
    }
    
    return len;
}

}