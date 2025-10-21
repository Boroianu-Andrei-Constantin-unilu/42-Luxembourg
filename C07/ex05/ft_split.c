#include <unistd.h>
#include <stdlib.h>

int is_sep(char c, char *charset) {
    int i = 0;
    while (charset[i]) {
        if (charset[i++] == c) {
            return 1;
        }
    }
    return 0;
}

int count_words(char *str, char *charset) {
    int i = 0, count = 0;
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

char *word_dup(char *str, int start, int end) {
    char *word = malloc(end - start + 1);
    int i = 0;

    while (start < end) {
        word[i++] = str[start++];
    }

    word[i] = '\0';
    return (word);
}

char **ft_split(char *str, char *charset) {
    int i = 0, j = 0, start;
    int words = count_words(str, charset);
    char **tab = malloc(sizeof(char *) * (words + 1));

    if (!tab) {
        return (NULL);
    }

    while (str[i]) {
        while (str[i] && is_sep(str[i], charset)) {
            i++;
        }

        start = i;
        while (str[i] && !is_sep(str[i], charset)) {
            i++;
        }

        if (i > start) {
            tab[j++] = word_dup(str, start, i);
        }
    }
    
    tab[j] = NULL;
    return (tab);
}
