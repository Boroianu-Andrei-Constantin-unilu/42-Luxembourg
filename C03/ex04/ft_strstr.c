#include <unistd.h>

char *ft_strstr(char *str, char *to_find) {
	int	i = 0;
	int	j = 0;

	if (to_find[0] == '\0') {
		return str;
    }
	while (str[i]) {
		while (str[i + j] == to_find[j] && str[i + j])
			j++;
		if (to_find[j] == '\0')
			return &str[i];
		i++;
	}
	return 0;
}