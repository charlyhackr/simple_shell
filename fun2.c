#include "head.h"

int guardarargumentos2(char *linea, char *argumentos[], char *comando)
{
        unsigned int cont = 0;
        unsigned int cont2 = 0;
        unsigned int cont3 = 1;
        unsigned int cont4 = 0;
        unsigned int cont5 = 0;
        unsigned int cont6 = 0;
        unsigned  int tam = tamanio(comando);


        while (linea[cont])
        {

                while(linea[cont2] != 58 && linea[cont2])
                {
			cont2++;
                        cont3++;
                }
                argumentos[cont] = malloc((sizeof(char) * (cont3 + tam + 2)));
                if (argumentos == NULL)
                {
                        exit(0);
                }
                while(linea[cont5] != 58 && linea[cont5] != '\0')
                {

                        argumentos[cont][cont4] = linea[cont5];
                        cont5++;
                        cont4++;
                }
                argumentos[cont][cont4] = '/';
                cont4++;
                while(comando[cont6])
                {
                        argumentos[cont][cont4] = comando[cont6];
                        cont4++;
                        cont6++;
                }

		argumentos[cont][cont4] = '\0';

                if(!linea[cont5])
                        break;
                cont++;
                cont2++;
                cont5++;
                cont3 = 0;
                cont4 = 0;
                cont6 = 0;

        }
        argumentos[cont+1] = NULL;
	return (1);
}
int concadenar(char *path, char **comando, char **environ, int cont)
{
        char *pathfinal = NULL;
        char **paths = NULL;
        char *separador = ":";
        unsigned int tampath = tamanio(path);
        unsigned int num = numerotokens(path, separador);
        unsigned int i = 0;
        unsigned int a = 0;
        struct stat ojo;

        pathfinal = malloc(sizeof(char) * tampath - 4);
        if (pathfinal == NULL)
                return(-1);
        funcionpath(pathfinal, path, tampath, comando, environ);
	paths = malloc(sizeof(char *) * (num + 1));
        if (paths == NULL)
                return(-1);
        for (i = 0; i < (num + 1); ++i)
                paths[i] = NULL;
        separarpath(pathfinal, comando[0], paths);
        while(paths[a])
        {
                if (stat(paths[a], &ojo) == 0)
                        execve(paths[a], comando, environ);
                a++;
        }
        _printf("sh: %d: %s: not found\n", cont, comando[0]);
        _free(paths, a);
        free(pathfinal);
        exit(0);
}
int separarpath(char *pathfinal, char *comando, char **paths)
{

        guardarargumentos2(pathfinal, paths, comando);

	return (1);
}
void _path(char **argumentos, char **environ, int numtokens, int cont)
{
        unsigned int path = 0;

	if (numtokens)
	{
	}
        if(comparar_envi(argumentos[0]) == 0)
        {
                path = search_env(argumentos, environ);
		concadenar(environ[path], argumentos, environ, cont);

        }
}
int comparar_envi(char *comando)
{

        unsigned int count = 0;
        char *path = "/bin";
        unsigned int pat = tamanio(path);

        while(path[count])
        {
                if(comando[count] != path[count])
                        return(0);
                count++;
        }
        if (count == pat)
                return(1);
        return (0);
}
