#include <unistd.h>

void ft_putstr_non_printable(char *str) {
    unsigned char c;
    char *hex = "0123456789abcdef";

    while (*str) {
        c = (unsigned char) *str;
        if (c < 32 || c > 126) {
            write(1, '\\', 1);
            write(1, &hex[c / 16], 1);
            write(1, &hex[c % 16], 1);
        } else {
            write(1, &c, 1);
        }
        str++;
    }
}