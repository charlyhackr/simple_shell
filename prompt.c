#include "head.h"
void funcionmain(pid_t pid, char **argumentos, int num, char *linea, char **environ, int cont)
{
        pid = fork();
        if (pid == 0)
        {
                argumentos = malloc(sizeof(char *) * (num + 1));
                if(argumentos == NULL)
                {
                        exit(0);
                }
                guardarargumentos(linea, argumentos);
                _path(argumentos,environ, num, cont);
                free(linea);
                _free(argumentos,num);
                exit(127);
        }
        else
        {
                wait(NULL);
        }


}

int main(void)
{
        size_t numbytes = 0;
        int bytesleidos = 0;
	int a = 0;
        char *linea = NULL;
        char **argumentos = NULL;
        char *separador = " ";
        unsigned int num = 0;
        pid_t pid = 0;
        extern char **environ;
        int cont = 1;
 	/*aqui la del control + c */
        signal(SIGINT, SigintHandler);

        while(1)
        {
                if (pid == -1)
                {
                        perror("Error:");
                        exit(0);
                }
		if (a != 0)
		{
			exit (0);
		}
                if (isatty(STDIN_FILENO))
                        _printf("$ ");

		if((bytesleidos = getline(&linea, &numbytes, stdin) == EOF))
		{
			printf("hola\n");
			exit(0);
		}
		if (linea[tamanio(linea) - 1] != '\n')
			a = 1;
		quitarsalto(linea);
		num = numerotokens(linea,separador);
		if(comparar(linea) == 1)
		{
			free(linea);
			exit(0);
		}
		if (num != 0)
		{
			funcionmain(pid, argumentos, num, linea, environ, cont);
		}
		cont++;

	}
	free(linea);
	_free(argumentos, num);
	return (0);
}
