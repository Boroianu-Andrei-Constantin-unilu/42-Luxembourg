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
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int ok1, ok2;
    long w = parse_long(argv[1], &ok1);
    long h = parse_long(argv[2], &ok2);

    if (!ok1 || !ok2 || w <= 0 || h <= 0) {
        fprintf(stderr, "Both width and height must be positive integers.\n");
        return 1;
    }

    rush((int)w, (int)h);
    return 0;
}
