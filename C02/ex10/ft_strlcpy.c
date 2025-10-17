#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size) {
    unsigned int i = 0;
    unsigned int len = 0;

    while (src[i] != '\0') {
        len++;
    }

    if (size == 0) {
        return len;
    }

    while (src[i] != '\0' && i < size - 1) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return len;
}