#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

typedef int t_bool;

#define TRUE 1
#define FALSE 0
#define EVEN(n) (n % 2 == 0)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0

#endif

void ft_putstr(char *str) {
    while(*str) {
        write(1, str++, 1);
    }
}

t_bool ft_is_even(int nbr) {
    return((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int argc, char **argv) {
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE) {
        ft_putstr(EVEN_MSG);
    } else {
        ft_putstr(ODD_MSG);
    }
    return SUCCESS;
}