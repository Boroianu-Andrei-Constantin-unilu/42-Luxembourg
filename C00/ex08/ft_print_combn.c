#include <unistd.h>

void print_comb(char *tab, int n) {
    write(1, tab, n);
    if (tab[0] != '9' - n + 1) {
        write(1, ", ", 2);
    }
}

void ft_print_combn(int n) {
    char tab[10];
    int i = 0;

    if (n <= 0 || n >= 10) {
        return;
    }

    while (i < n) {
        tab[i] = '0' + i;
        i++;
    }

    while (1) {
        print_comb(tab, n);
        i = n - 1;

        while (i >= 0 && tab[i] == '9' - n + 1 + i) {
            i--;
        }

        if (i < 0) {
            break;
        }

        tab[i]++;

        while (i++ < n) {
            tab[i] = tab[i - 1] + 1;
        }
    }
}