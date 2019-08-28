#include "head.h"

int _free(char **token, int tam)
{
        int a = 0;

        while(a < tam)
        {

                free(token[a]);
                a++;
        }
        free(token);

        return(1);
}
