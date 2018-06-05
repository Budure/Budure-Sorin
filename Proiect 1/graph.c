#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

int i,j,n,ac,x,k,iterator1,iterator2,viz[1000],nod,b=1;

void generare_graf(int x,double a[1000][1000])
{
    time_t t;
    srand((unsigned) time(&t));

    for(i=1;i<=x;i++)
        {
         iterator1=rand() % 999;
         iterator2=rand() % 999;
         if(a[iterator1][iterator2]==1)
            i--;
         else
            a[iterator1][iterator2]=1;
        }
}
void dfc(int nod,double a[1000][1000]){
int k;
viz[nod]=1;
    for(k=1;k<1000;k++)
    {
        if(a[nod][k]){
          if(!viz[k]){
            dfc(k,a);
          }
          else{
            ac=1;
          }
        }

    }
}
void sort_topologic(double a[1000][1000])
{
    double flag[1000]={0},count=1000;
    int gradientern;

    while(count !=0 )
    {
      for(i=0;i<=1000;i++)
      {gradientern=0;
        if(flag[i]==0)
        {
           for(j=0;j<=1000;j++)
           {
               gradientern+=a[j][i];
           }
           if(gradientern==0)
           {
               flag[i]=1;
               printf("%d ",i);
               count--;
               for(j=0;j<1000;j++){
                 a[i][j]=0;
               }
           }
        }
       }
     }
    printf("\n");
}
