#include <stdlib.h>

int	is_sep(char c, char *charset) {
	int	i = 0;
	while (charset[i]) {
		if (c == charset[i]) {
			return (1);
        }
		i++;
	}
	return 0;
}

int	count_words(char *str, char *charset) {
	int	i = 0;
	int	count = 0;

	while (str[i]) {
		while (str[i] && is_sep(str[i], charset)) {
			i++;
        }
		if (str[i]) {
			count++;
        }
		while (str[i] && !is_sep(str[i], charset)) {
			i++;
        }
	}
	return count;
}

char *word_dup(char *str, char *charset) {
	int	i = 0;
	int	len = 0;
	char *word = malloc(sizeof(char) * (len + 1));

	while (str[len] && !is_sep(str[len], charset)) {
		len++;
    }

	if (!word) {
		return NULL;
    }

	while (i < len) {
		word[i] = str[i];
		i++;
	}

	word[i] = '\0';
	return word;
}

char **ft_split(char *str, char *charset) {
	int	i = 0;
	int	j = 0;
	char **tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));

	if (!tab) {
		return NULL;
    }

	while (str[i]) {
		while (str[i] && is_sep(str[i], charset)) {
			i++;
        }

		if (str[i]) {
			tab[j] = word_dup(&str[i], charset);
			j++;
		}

		while (str[i] && !is_sep(str[i], charset)) {
			i++;
        }
	}
	tab[j] = NULL;
	return tab;
}