#include <unistd.h>

int *ft_range(int min, int max) {
    int i = 0;
    int size = max - min;
    int *range = (int *)malloc(sizeof(int) * size);

    if (min >= max) {
        return NULL;
    }

    if (!range) {
        return NULL;
    }

    while (i < size) {
        range[i] = min + i;
        i++;
    }

    return range;
}