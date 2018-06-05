#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"



int main()
{

    int i,j,ac,x,b=1;

    time_t t;
    srand((unsigned)time(&t));
    x = rand() % 1000;
    printf("%d \n",x);

    do
    {
        ac=0;
        generare_graf(x,a);
        dfc(b,a);
        if(ac==1){
            for(i=0;i<1000;i++){
                for(j=0;j<1000;j++){
                    a[i][j]=0;
                }
            }
        }
    }while(ac==1);

    sort_topologic(a);

    return 0;
}





