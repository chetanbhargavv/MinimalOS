/* String utility functions implementation */

#include "string.h"
#include "types.h"

/**
 * strlen - Calculate length of string
 * @str: String to measure
 * 
 * Returns: Length of string (excluding null terminator)
 */
size_t strlen(const char* str) {
    size_t len = 0;
    
    if (!str) {
        return 0;
    }
    
    while (str[len]) {
        len++;
    }
    
    return len;
}

/**
 * strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * 
 * Returns: 0 if equal, <0 if s1 < s2, >0 if s1 > s2
 */
int strcmp(const char* s1, const char* s2) {
    if (!s1 || !s2) {
        return s1 == s2 ? 0 : (s1 ? 1 : -1);
    }
    
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

/**
 * strncmp - Compare first n characters of two strings
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of characters to compare
 * 
 * Returns: 0 if equal, <0 if s1 < s2, >0 if s1 > s2
 */
int strncmp(const char* s1, const char* s2, size_t n) {
    if (!s1 || !s2 || n == 0) {
        return 0;
    }
    
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    if (n == (size_t)-1) {
        return 0;
    }
    
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

/**
 * strcpy - Copy string
 * @dest: Destination buffer
 * @src: Source string
 * 
 * Returns: Destination pointer
 */
char* strcpy(char* dest, const char* src) {
    char* d = dest;
    
    if (!dest || !src) {
        return dest;
    }
    
    while ((*d++ = *src++));
    
    return dest;
}

/**
 * strncpy - Copy at most n characters from string
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to copy
 * 
 * Returns: Destination pointer
 */
char* strncpy(char* dest, const char* src, size_t n) {
    size_t i;
    
    if (!dest || !src) {
        return dest;
    }
    
    for (i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }
    
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    
    return dest;
}
