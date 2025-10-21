#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str) {
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

char *ft_strcat(char *dest, char *src) {
    int i = 0;
    int j = 0;

    while (dest[i]) {
        i++;
    }

    while (src[j]) {
        dest[i++] = src[j++];
    }

    dest[i] = '\0';
    return dest;
}

char *ft_strjoin(int size, char **strs, char *sep) {
    int total_len = 0;
    char *result;

    if (size == 0) {
        result = malloc(1);
        if (result) {
            result[0] = '\0';
        }
        return result;
    }

    for (int i = 0; i < size; i++) {
        total_len += ft_strlen(strs[i]);
    }

    total_len += (size - 1) * ft_strlen(sep);
    result = (char *)malloc(sizeof(char) * (total_len + 1));

    if (!result) {
        return (NULL);
    }

    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        ft_strcat(result, strs[i]);
        if (i < size - 1) {
            ft_strcat(result, sep);
        }
    }
    return result;
}
