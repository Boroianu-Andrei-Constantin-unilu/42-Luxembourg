#include <unistd.h>

void ft_putnbr(int nb) {
	long n = nb;
	if (n < 0) {
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10) {
		ft_putnbr(n / 10);
    }
	n = n % 10 + '0';
	write(1, &n, 1);
}