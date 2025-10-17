#include <unistd.h>

static void print_line(int x, char left, char mid, char right) {
    if (x <= 0) {
        return;
    }

    if (x == 1) {
        write(1, &left, 1);
        write(1, "\n", 1);
        return;
    }

    write(1, &left, 1);
    for (int i = 0; i < x - 2; i++) {
        write(1, &mid, 1);
    }

    write(1, &right, 1);
    write(1, "\n", 1);
}

void rush(int x, int y) {
    if (x <= 0 || y <= 0) {
        return;
    }

    if (y == 1) {
        print_line(x, '/', '*', '\\');
        return;
    }

    print_line(x, '/', '*', '\\');
    for (int i = 0; i < y - 2; i++) {
        if (x == 1) {
            write(1, "*", 1);
            write(1, "\n", 1);
            continue;
        }

        write(1, "*", 1);
        for (int j = 0; j < x - 2; j++) {
            write(1, " ", 1);
        }
        write(1, "*", 1);
        write(1, "\n", 1);
    }

    if (y > 1) {
        print_line(x, '\\', '*', '/');
    }
}