#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

void readData();
void printTimpi();
void explorare(int u);
void DFS ();
void topSort();
struct Nod
{
int val;
int nrVecini;
int * vecini;
int culoare;
int parinte;
int tDescoperire;
int tFinal;
};
struct Nod * graf;

#endif // GRAPH_H_INCLUDED
