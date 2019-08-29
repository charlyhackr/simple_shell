#include "head.h"

/**
 * __putchar - Fuction that prints to the std output
 * @c: char to print
 * Return: the char printed
 */
int __putchar(char c)
{
	return (write(1, &c, 1));
}
