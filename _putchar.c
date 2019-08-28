#include "head.h"

/**
 * _putchar - Fuction that prints to the std output
 * @c: char to print
 * Return: the char printed
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
