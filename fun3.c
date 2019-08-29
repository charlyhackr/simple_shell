#include "head.h"

/**
 * numerotokens - function for tokens
 * @linea: pointer string linea
 * @separador: pointer for separator
 * Return: return to cont2
 */

int numerotokens(char *linea, char *separador)
{
	unsigned int cont = 0;
	unsigned int cont2 = 1;

	if (!linea[cont])
		return (0);

	while (linea[cont] == separador[0] || linea[cont] == 9)
	{
		cont++;
		if (linea[cont] == '\0')
			return (0);
	}
	while (linea[cont] != '\0')
	{
		if (linea[cont] == separador[0] && linea[cont + 1] == '\0')
			cont2--;
		if (linea[cont] == separador[0] && linea[cont + 1] != separador[0])
			cont2++;
		cont++;
	}
	return (cont2);
}

/**
 * guardarargumentos - funciton for storage argumemts
 * @linea: pointer to linea
 * @argumentos: array of arguments
 * Return: 1 if error
 */

int guardarargumentos(char *linea, char *argumentos[])
{
	unsigned int cont = 0, cont2 = 0, cont3 = 1, cont4 = 0;
	unsigned int cont5 = 0;

	while (linea[cont])
	{
		while (linea[cont2] == 32 || linea[cont2] == 9)
			cont2++;

		while (linea[cont2] != 32 && linea[cont2])
		{
			cont2++;
			cont3++;
		}
		while (linea[cont2] == 32 || linea[cont2] == 9)
			cont2++;

		argumentos[cont] = malloc((sizeof(char) * cont3 + 1));
		if (argumentos == NULL)
			exit(0);

		while (linea[cont5] == 32 || linea[cont5] == 9)
			cont5++;

		while ((linea[cont5] != 32 && linea[cont5] != 9) && linea[cont5] != '\0')
		{
			argumentos[cont][cont4] = linea[cont5];
			cont5++;
			cont4++; }
		argumentos[cont][cont4] = '\0';
		while (linea[cont5] == 32 || linea[cont5] == 9)
			cont5++;

		if (!linea[cont5])
			break;
		cont++;
		cont3 = 0;
		cont4 = 0; }
	argumentos[cont + 1] = NULL;
	free(linea);
	return (1);
}

/**
 * quitarsalto - function for delete new line
 * @linea: string  for linea
 * Return: pointer linea
 */

char quitarsalto(char *linea)
{
	int ta = tamanio(linea);

	if (linea[ta - 1] == '\n')
		linea[ta - 1] = '\0';

	return (*linea);
}

/**
 * tamanio - function for size
 * @linea: pointer linea
 * Return: return to contador
 */

int tamanio(char *linea)
{
	unsigned int contador = 0;

	while (linea[contador])
	{
		contador++;
	}
	return (contador);
}

/**
 * penv - fucntion for staroge  environ
 * @environ: pointer storage environ
 * @comando: pointer for comando string
 * Return: return 1 if error
 */

int penv(char **environ, char *comando)
{
	int a = 0;

	if (comando[0] != 'e')
		return (0);
	if (comando[1] != 'n')
		return (0);
	if (comando[2] != 'v')
		return (0);
	while (environ[a])
	{
		_printf("%s\n", environ[a]);
		a++;
	}
	return (1);
}
