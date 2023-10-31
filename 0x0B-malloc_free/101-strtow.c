#include <stdlib.h>
#include "main.h"

int count_word(char *s) {
	int flag = 0, c = 0, w = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')
			flag = 0;
		else if (flag == 0) {
			flag = 1;
			w++;
		}
	}

	return w;
}

char **strtow(char *str) {
	if (str == NULL)
		return NULL;

	int len = 0, words, c = 0, start = 0, end = 0, k = 0;

	while (str[len] != '\0')
		len++;

	words = count_word(str);

	if (words == 0)
		return NULL;

	char **matrix = (char **)malloc(sizeof(char *) * (words + 1));

	if (matrix == NULL)
		return NULL;

	for (int i = 0; i <= len; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			if (c) {
				end = i;
				char *tmp = (char *)malloc(sizeof(char) * (c + 1));

				if (tmp == NULL) {
					for (int j = 0; j < k; j++) {
						free(matrix[j]);
					}
					free(matrix);
					return NULL;
				}

				for (int j = start; j < end; j++) {
					tmp[j - start] = str[j];
				}

				tmp[c] = '\0';
				matrix[k] = tmp;
				k++;
				c = 0;
			}
		} else if (c++ == 0) {
			start = i;
		}
	}

	matrix[k] = NULL;
	return matrix;
}
