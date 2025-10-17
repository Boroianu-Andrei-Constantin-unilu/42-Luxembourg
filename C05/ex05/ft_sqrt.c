#include <unistd.h>

int	ft_sqrt(int nb) {
	int	i = 1;

	if (nb <= 0) {
		return (0);
    }

	while (i * i <= nb && i <= 46340) {
		if (i * i == nb) {
			return i;
        }
		i++;
	}
	return 0;
}