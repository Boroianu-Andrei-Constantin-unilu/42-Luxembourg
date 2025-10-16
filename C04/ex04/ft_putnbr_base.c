#include <unistd.h>

int	check_base(char *base) {
	int	i = 0;
	int	j;

	while (base[i]) {
		if (base[i] == '+' || base[i] == '-') {
			return (0);
        }
		j = i + 1;
		while (base[j]) {
			if (base[i] == base[j]) {
				return (0);
            }
			j++;
		}
		i++;
	}
	if (i < 2) {
		return (0);
    }
	return (1);
}

void ft_putnbr_base(int nbr, char *base) {
	long nb;
	int	size;

	if (!check_base(base)) {
		return;
    }
	nb = nbr;
	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	size = 0;
	while (base[size]) {
		size++;
    }
	if (nb >= size) {
		ft_putnbr_base(nb / size, base);
    }
	write(1, &base[nb % size], 1);
}