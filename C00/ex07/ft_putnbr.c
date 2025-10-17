#include <unistd.h>

void ft_putnbr(int nb) {
    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    } else if (nb >= 10) {
        ft_putnbr(nb / 10);
    } else {
        write(1, nb % 10 + '0', 1);
    }
}