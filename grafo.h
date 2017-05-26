#include <vector>
using namespace std;

typedef struct{
	int x, y;
	int peso;	
	
}Aresta;

typedef struct{

	vector <vector <int> > listaAdj;
	vector <vector <int> > matrizAdj;
	vector <vector <int> > matrizInc;
	vector <Aresta> listaArestas;
	vector <vector <int> > pesos;
	
}Grafo;
