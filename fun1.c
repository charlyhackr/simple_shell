#include "head.h"

int funcionpath(char *pathfinal, char *path, int tam, char **comando, char **environ)
{
        int cont = 0;
        int igual = 5;

        if(path[5] == 58)
        {
                execve(comando[0],comando,environ);
        }
        if (igual < tam)
        {
                while(igual < tam)
                {
                        pathfinal[cont] = path[igual];
                        igual++;
                        cont++;
                }
        }
        else
                execve(comando[0],comando, NULL);
	return (0);
}
int search_env(char **argumentos, char **environ)
{
        int cont = 0;
	if(argumentos)
	{
	}
        while(environ[cont])
        {
                if(comparar_env(environ[cont]) == 1)
                {
                        break;
                }
                cont++;
        }
        return(cont);

}
int comparar_env(char *comando)
{

        int count = 0;
        char *path = "PATH=";
        int pat = tamanio(path);
        char *dospuntos = ":";
        if(path[0] == dospuntos[0])
                count++;
        if(path[0] == dospuntos[0])
                count++;

        while(path[count])
        {
                if(comando[count] != path[count])
                        return(0);
                count++;
        }
        if (count == pat)
                return(1);


        return (1);
}
void SigintHandler(int sigint)
{
        (void) sigint;
        signal (SIGINT, SigintHandler);
        fflush(stdout);
}
