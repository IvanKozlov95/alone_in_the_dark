#include <unistd.h>
#include <stdlib.h>

#define _tolower(c) ( ((c) >= 'A' && (c) <= 'Z') ? (c) + ' ' : (c) )
#define _istab(c) ( (c) == '\t' || (c) == ' ' )

int		_strlen(char *s) {
	int		i = -1;

	while (s[++i]) ;
	return i;
}

int		_strcmp(char *a, char *b) {
	while (*a && *b) {
		unsigned char aa = _tolower(*a);
		unsigned char bb = _tolower(*b);
		if (aa != bb)
			return aa - bb;
		a++; b++;
	}
	return 0;
}

int		count_words(char *s) {
	int		count = 0;
	int		cur_word_len = 0;

	while (s && *s) {
		if (!_istab(*s)) {
			cur_word_len++;
		} else {
			if (cur_word_len > 0)
				count++;
			cur_word_len = 0;
		}
		s++;
	}
	return count + (cur_word_len > 0);
}

char	**split(char *s) {
	int		i = 0;
	int		first = 1;
	int		words_count = count_words(s);
	char	**words = malloc(sizeof(char *) * (words_count + 1));

	if (!words)
		return NULL;
	words[words_count] = NULL;
	while (s && *s) {
		if (!_istab(*s) && first) {
			words[i++] = s;
			first = 0;
		} else if (_istab(*s)) {
			first = 1;
			*s = '\0';
		}
		s++;
	}
	return words;
}

int		cmp(char *a, char *b) {
	int		alen = _strlen(a);
	int		blen = _strlen(b);

	if (alen != blen)
		return alen - blen;
	return _strcmp(a, b);
}

void	swap(char **p, int i, int j) {
	char *tmp = p[i];
	p[i] = p[j];
	p[j] = tmp;
}

void	sort(char **words) {
	int		i = 0;
	int		swapped = 1;

	while (swapped) {
		i = 0;
		swapped = 0;
		while (words[++i]) {
			if (cmp(words[i - 1], words[i]) > 0) {
				swapped = 1;
				swap(words, i - 1, i);
			}
		}
	}
}

void	print(char **words) {
	int		i = 0;
	int		len = _strlen(*words);

	while (words && words[i]) {
		int		cur_len = _strlen(words[i]);
		if (cur_len == len && i != 0)
			write(1, " ", 1);
		else if (cur_len != len)
			write(1, "\n", 1);
		write(1, words[i], cur_len);
		len = cur_len;
		i++;
	}
}

int		main(int ac, char **av) {
	if (ac == 2) {
		char	**words = split(av[1]);
		sort(words);
		print(words);
		free(words);
	}
	write(1, "\n", 1);
}
