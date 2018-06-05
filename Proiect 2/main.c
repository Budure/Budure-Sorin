#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"


/* citeste lista de adiacenta din fisier */
int n;

int main(void){
int i;

//incarca graful din fisier
readData();

//parcurgere BFS
DFS();

//afisarea timpilor
printTimpi();

//sortare topologica
topSort();
printf( "Sortare topologoca: " );
for ( i = 0; i < n; ++i )
printf ( "%d ", graf[i].val );
printf("\n");

for( i = 0; i < graf[i].nrVecini; ++i )
free(graf[i].vecini);
free(graf);
return 0;
}
