#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

int n;

void readData()
{
FILE * f;
int i, j;

f = fopen( "in2.txt","r" );
assert( f );

fscanf( f, "%d", &n );
graf = ( struct Nod * ) malloc ( n * sizeof( struct Nod ) );

for ( i = 0; i < n; ++i ) {
graf[i].val = i;
fscanf( f, "%d", &graf[i].nrVecini );
graf[i].vecini = ( int * ) malloc ( graf[i].nrVecini * sizeof ( int ) );
for ( j = 0; j < graf[i].nrVecini; ++j )
fscanf( f, "%d", &graf[i].vecini[j] );
graf[i].parinte = -1;
graf[i].culoare = 0;
graf[i].tDescoperire = -1;
graf[i].tFinal = -1;
}
fclose( f );
}


void printTimpi()
{
int i;
printf( "\n" );
for ( i = 0; i < n; ++i )
printf ( "Nod %d: descoperit la t=%d, explorat la t=%d \n", i, graf[i].tDescoperire, graf[i].tFinal );
printf( "\n" );
}
int timp = 0;

/* parcurgere DFS a grafului */
void explorare(int u) {

graf[u].tDescoperire = timp++;
graf[u].culoare = 1;
int j;
for(j = 0 ; j < graf[u].nrVecini ; j++) {
int x = graf[u].vecini[j];
if(graf[x].culoare ==0) {
graf[x].parinte = u;
explorare(x);
}
}
graf[u].culoare = 2;
graf[u].tFinal = timp++;

}

void DFS ()
{
int i;
for (i=0; i < n ; i++)
if(graf[i].culoare == 0)
explorare(i);
}



/* sortare topologica */
void topSort()
{
int ok = 0 , i , j;
struct Nod aux;
while (ok == 0) {
ok = 1;
for(i=0; i < n-1 ; i++)
if(graf[i].tFinal < graf[i+1].tFinal) {
ok = 0;
aux = graf[i];
graf[i]=graf[i+1];
graf[i+1]=aux;
}
}
}
