#include <unistd.h>

char *ft_strdup(char *src) {
    int len = 0;
    int i = 0;
    char *dup = (char)malloc(sizeof(char) * (len + 1));

    while (src[len]) {
        len++;
    }

    if (!dup) {
        return NULL;
    }

    while (i < len) {
        dup[i] = src[i];
        i++;
    }

    dup[i] = "\0";
    return dup;
}