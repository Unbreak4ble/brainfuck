#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char *input) {
	unsigned char bytes[30000] = {0};
	unsigned char *ptr = bytes;
	char current_char;
	size_t loop;

	for (size_t i = 0; input[i] != 0; i++) {
		current_char = input[i];
		if (current_char == '>')
			++ptr;
		else if (current_char == '<')
			--ptr;
		else if (current_char == '+')
			++*ptr;
		else if (current_char == '-')
			--*ptr;
		else if (current_char == '.')
			putchar(*ptr);
		else if (current_char == ',')
			*ptr = getchar();
		else if (current_char == '[')
			continue;
		else if (current_char == ']' && *ptr) {
			loop = 1;
			while (loop > 0) {
				current_char = input[--i];
				if (current_char == '[')
					loop--;
				else if (current_char == ']')
					loop++;
			}
		}
	}
}

char *toPlus(int len) {
	char bf[30000] = {};

	for (int s = 0; s < len; s++)
		strcat(bf, "+");

	char *bfr = &bf[0];

	return bfr;
}

char *encode(char str[]) {
	char bf[30000] = {};

	size_t size = strlen(str);

	for (int s = 0; s < size; s++) {
		int byteChar = (int)str[s];
		char *plus = toPlus(byteChar);
		strcat(plus, ".>\n");
		strcat(bf, plus);
	}

	char *stre = (char *)malloc(sizeof(char) * strlen(bf));
	strcpy(stre, bf);

	return stre;
}

int main() {
	char *str = encode("Hello World.");

	printf("%s\n", str);

	decode(str);

	free(str);
}
