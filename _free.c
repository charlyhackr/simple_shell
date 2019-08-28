#include "head.h"

/**
 * _free - free the memory
 * @token: pointer a string
 * @tam: string size
 * Return: 1 not compile
 */
int _free(char **token, int tam)
{
	int a = 0;

	while (a < tam)
	{
		free(token[a]);
		a++;
	}
	free(token);
	return (1);
}
