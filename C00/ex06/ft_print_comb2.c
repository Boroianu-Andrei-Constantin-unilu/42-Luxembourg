#include <unistd.h>

void ft_print_comb2(void) {
    int a, b;

    a = 0;
    while (a <= 98) {
        b = a + 1;
        while (b <= 99) {
            write(1, a / 10 + '0', 1);
            write(1, a % 10 + '0', 1);
            write(1, " ", 1);
            write(1, b / 10 + '0', 1);
            write(1, b % 10 + '0', 1);

            if (!(a == 98 && b == 99)) {
                write(1, ", ", 2);
            }
            b++;
        }
        a++;
    }
}