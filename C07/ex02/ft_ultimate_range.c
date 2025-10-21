#include <unistd.h>

int ft_ultimate_range(int **range, int  min, int max) {
    int size = max - min;
    int i = 0;

    if (min >= max) {
        *range = NULL;
        return 0;
    }

    *range = (int *)malloc(sizeof(int) * size);

    if (!*range) {
        return -1;
    }

    while (i < size) {
        (*range)[i] = min + i;
        i++;
    }

    return size;
}