#include <unistd.h>

void ft_ultimate_div_mod(int *a, int *b) {
    if (b != 0) {
        int div = *a / *b;
        int mod = *a % *b;
        *a = div;
        *b = mod;
    }
}