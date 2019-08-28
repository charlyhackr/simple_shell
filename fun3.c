#include "head.h"

int numerotokens(char *linea,char *separador)
{
        unsigned int cont = 0;
        unsigned int cont2 = 1;

        if(!linea[cont])
                return(0);

        while(linea[cont] == separador[0] || linea[cont] == 9)
        {
                cont++;
                if(linea[cont] == '\0')
                        return(0);
        }
        while (linea[cont] != '\0')
        {
                if(linea[cont] == separador[0] && linea[cont + 1] == '\0')
                        cont2--;
                if (linea[cont] == separador[0] && linea[cont + 1] != separador[0])
                        cont2++;
                cont++;
        }
        return (cont2);
}
int guardarargumentos(char *linea, char *argumentos[])
{
        unsigned int cont = 0;
        unsigned int cont2 = 0;
        unsigned int cont3 = 1;
        unsigned int cont4 = 0;
        unsigned int cont5 = 0;


        while (linea[cont])
        {
                while(linea[cont2] == 32 || linea[cont2] == 9)
                {
                        cont2++;
                }

                while(linea[cont2] != 32 && linea[cont2])
                {
                        cont2++;
                        cont3++;
                }
                while(linea[cont2] == 32 || linea[cont2] == 9)
                {
                        cont2++;
                }
                argumentos[cont] = malloc((sizeof(char) * cont3 + 1));
                if (argumentos == NULL)
                {
                        exit(0);
                }
                while(linea[cont5] == 32 || linea[cont5] == 9)
                {
                        cont5++;
                }
                while((linea[cont5] != 32 && linea[cont5] != 9) && linea[cont5] != '\0')
                {

                        argumentos[cont][cont4] = linea[cont5];
                        cont5++;
                        cont4++;
                }
                argumentos[cont][cont4] = '\0';
		while(linea[cont5] == 32 || linea[cont5] == 9)
                {
                        cont5++;
                }
                if(!linea[cont5])
                        break;
                cont++;
                cont3 = 0;
                cont4 = 0;

        }
        argumentos[cont+1] = NULL;
	free(linea);
	return (1);
}
char quitarsalto(char *linea)
{

        int ta = tamanio(linea);
	if (linea[ta - 1] == '\n')
		linea[ta - 1] = '\0';

        return(*linea);
}
int tamanio(char *linea)
{

        unsigned int contador = 0;

        while (linea[contador])
        {
                contador++;
        }
        return (contador);

}
