#include "head.h"

/**
 * comparar - function to comparte string
 * @linea: pointer to string linea
 * Return: return 0 if not error
 */

int comparar(char *linea)
{

	int count = 0;
	int count2 = 0;
	char *puntero2 = linea;
	char *exit = "exit";
	int tam = tamanio(exit);

	if (puntero2[0] == '\0')
		return (0);

	while (puntero2[count] == 32 || puntero2[count] == 9)
		count++;

	while (puntero2[count])

	{

		if (puntero2[count] != exit[count2])
			return (0);

		count++;
		count2++;
	}
	if (count2 == tam)
	return (1);
	else
		return (0);
}
