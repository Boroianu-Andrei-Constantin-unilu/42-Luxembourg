#include <unistd.h>

int	check_base(char *base) {
	int	i = 0;
	int	j;

	while (base[i]) {
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32) {
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

int	base_index(char c, char *base) {
	int	i = 0;

	while (base[i]) {
		if (base[i] == c) {
			return (i);
        }
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base) {
	int	sign = 1;
	int	result = 0;
	int	i = 0;
	int	b_len = 0;

	if (!check_base(base)) {
		return (0);
    }

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') {
		i++;
    }
	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			sign *= -1;
        }
		i++;
	}

	while (base[b_len]) {
		b_len++;
    }
	while (base_index(str[i], base) != -1) {
		result = result * b_len + base_index(str[i], base);
		i++;
	}
	return (result * sign);
}