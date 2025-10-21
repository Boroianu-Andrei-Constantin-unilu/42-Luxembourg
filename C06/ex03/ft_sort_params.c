#include <unistd.h>

int	ft_strcmp(char *s1, char *s2) {
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i]) {
		i++;
    }
	return s1[i] - s2[i];
}

void ft_swap(char **a, char **b) {
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(int argc, char **argv) {
	int	i = 1;
	int	j;

	while (i < argc - 1) {
        j = 1;
		while (j < argc - 1) {
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}

    int k = 1;

	while (k < argc) {
		j = 0;
		while (argv[k][j]) {
			write(1, &argv[k][j++], 1);
        }
		write(1, "\n", 1);
		k++;
	}
	return 0;
}