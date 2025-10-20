#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str) {
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}

int is_valid_base(char *base) {
    if (ft_strlen(base) < 2) {
        return 0;
    }

    for (int i = 0; base[i]; i++) {
        if (base[i] == '+' || base[i] == '-' || base[i] <= 32) {
            return 0;
        }
        for (int j = i + 1; base[j]; j++) {
            if (base[i] == base[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int base_index(char c, char *base) {
    int i = 0;
    while (base[i]) {
        if (base[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int ft_atoi_base(char *str, char *base) {
    int i = 0, sign = 1, result = 0, idx;
    int blen = ft_strlen(base);

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) {
        i++;
    }

    while (str[i] == '+' || str[i] == '-') {
        if (str[i++] == '-') {
            sign *= -1;
        }
    }

    while ((idx = base_index(str[i], base)) != -1) {
        result = result * blen + idx, i++;
    }
    return result * sign;
}

char *ft_putnbr_base(int nbr, char *base) {
    int blen = ft_strlen(base);
    int n = nbr;
    int len = (nbr <= 0);

    while (n && ++len) {
        n /= blen;
    }

    char *res = malloc(len + 1);
    if (!res) {
        return NULL;
    }

    res[len] = '\0';
    if (nbr == 0) {
        res[0] = base[0];
    }

    if (nbr < 0) {
        res[0] = '-';
        nbr = -nbr;
    }

    while (nbr) {
        res[--len] = base[nbr % blen];
        nbr /= blen;
    }
    return res;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to) {
    if (!is_valid_base(base_from) || !is_valid_base(base_to)) {
        return NULL;
    }

    int n = ft_atoi_base(nbr, base_from);
    return ft_putnbr_base(n, base_to);
}
