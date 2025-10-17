#include <unistd.h>

unsigned int ft_strlen(char *str) {
	unsigned int len = 0;
	while (str[len])
		len++;
	return len;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {
	unsigned int i;
	unsigned int j = 0;
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len) {
		return size + src_len;
    }
	i = dest_len;
	while (src[j] && (i + 1) < size) {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return dest_len + src_len;
}