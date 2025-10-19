#include <stdio.h>
#include <stdlib.h>

/* forward declaration of rush implemented in rush00.c */
void rush(int x, int y);

static long parse_long(const char *s, int *ok)
{
    char *end;
    long val = strtol(s, &end, 10);
    if (end == s || *end != '\0') {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return val;
}

int main(int argc, char **argv)
{
    /* Default values when no args provided to preserve previous behavior */
    int width = 5;
    int height = 3;

    if (argc == 3) {
        int ok1, ok2;
        long w = parse_long(argv[1], &ok1);
        long h = parse_long(argv[2], &ok2);

        if (!ok1 || !ok2 || w <= 0 || h <= 0) {
            fprintf(stderr, "Both width and height must be positive integers.\n");
            return 1;
        }
        width = (int)w;
        height = (int)h;
    } else if (argc != 1) {
        fprintf(stderr, "Usage: %s [width height]\nWhen no arguments are provided defaults to 5 3.\n", argv[0]);
        return 1;
    }

    rush(width, height);
    return 0;
}
