#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void remove_spaces(char *str)
{
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
		{
			for (j = i; str[j] != '\0'; j++)
			{
				str[j] = str[j + 1];
			}
			i = i - 1;
		}
	}
}

void insert_spaces(char *str)
{
	int i, j, length = strlen(str);
	char temp;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isupper(str[i]))
		{
			for (j = i; str[j + 1] != '\0'; j++)
			{
				temp = str[j + 1];
				str[j + 1] = str[j];
			}
			str[i] = ' ';
		}
	}
}

void string_toupper(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
	}
}

void reverse_string(char *str)
{
	int length = strlen(str), i;

	for (i = length - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}

void randomize_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))
		{
			if (rand() % 2)
			{
				str[i] = rand() % 26 + 'a';
			}
			else
			{
				str[i] = rand() % 26 + 'A';
			}
		}
	}
}

// Function that takes an integer array, the length of the array, and an integer, and checks
// whether the integer appears within the array, returning 1 if found, returning 0 otherwise.
int value_is_in_array(int *index_arr, int length, int val)
{
	int i;

	for (i = 0; i < length; i++)
	{
		if (index_arr[i] == val)
		{
			return 1;
		}
	}
	return 0;
}

void scramble_string(char *str)
{
	int i, j = 0, length = strlen(str), rand_index, index_exceptions[100];
	char dest[100] = "";

	for (i = 0; i < length; i++)
	{
		index_exceptions[i] = -1;
	}

	while (j < length)
	{
		rand_index = rand() % length;

		if (!value_is_in_array(index_exceptions, length, rand_index))
		{
			dest[rand_index] = str[j];
			index_exceptions[j] = rand_index;
			j++;
		}
	}
	strcpy(str, dest);
}

int main(void)
{
	char str[100] ="";

	printf("Enter a single word to scramble it: ");
	scanf("%s", str);
	//fgets(str, 100, stdin);
	srand(time(NULL));
	
	//reverse_string(str);
	//remove_spaces(str);
	//printf("%s\n", str);
	//string_toupper(str);
	//printf("%s\n", str);
	//insert_spaces(str);
	//printf("%s\n", str);
	//randomize_string(str);
	//printf("%s\n", str);
	//char ch = 'b';
	//printf("%d\n", 'b');

	scramble_string(str);
	printf("%s\n", str);
	return 0;
}
