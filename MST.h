#include "buscas.h"
#include <algorithm>

/*** Kruskal ***/

int find(int x, vector<int> pai){
    if(pai[x] == x) 
		return x;
    return pai[x] = find(pai[x],pai);
}

void join(int a, int b, vector<int> &pai){
    
    a = find(a,pai);
    b = find(b,pai);
    
    pai[b] = a;
    
}

void kruskal(Grafo G){
    
	vector<int> pai;
	pai.resize(0);
	
	vector<Aresta> arvore;
	arvore.resize(0);
	
    for(int i=0;i<G.listaAdj.size();i++) 
		pai.push_back(i);
    
    sort(G.listaArestas.begin(), G.listaArestas.end(), compara);
    
    for(int i=0;i<G.listaArestas.size();i++){
        
        if( find(G.listaArestas[i].x, pai) != find(G.listaArestas[i].y, pai) ){ // se não houver caminho entre elas
            join(G.listaArestas[i].x, G.listaArestas[i].y, pai);
            
            arvore.push_back(G.listaArestas[i]);
        }
        
    }
    
    for(int i=0;i<arvore.size();i++)
		cout << arvore[i].x << " " << arvore[i].y << " " << arvore[i].peso << endl;
    
}
