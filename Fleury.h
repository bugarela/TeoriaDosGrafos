#include "conexidade.h"
using namespace std;

void removeAresta(pair<int,int> aresta, Grafo G){

	int a = aresta.first;
	int b = aresta.second;
	
	for(auto conexao : G.listaAdj[a])
		if(conexao = b)
			G.listaAdj[a].erase(G.listaAdj[a].begin()+conexao);
	for(auto conexao : G.listaAdj[b])
		if(conexao = a)
			G.listaAdj[b].erase(G.listaAdj[b].begin()+conexao);

}

bool ehPonte(pair<int,int> aresta, Grafo G){
	Grafo GTemp = G;
	removeAresta(aresta,GTemp);
	if(!ehConexo(GTemp))
		return false;
	return true;
}

/*bool ehEuclidiano(Grafo G){
	if(!ehConexo(G))
		return false;
	
	int noAtual = 0;
	int noDestino; 
	int i=0;
	
	Grafo GTemp = G;
	
	while (noDestino != 0){
		
		if(GTemp.listaAdj[noAtual].size() == 0)
			return false;
		else
			noDestino = GTemp.listaAdj[noAtual][0];
			
		while(ehPonte(<noAtual,noDestino>,G)){
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()<i)
				noDestino=GTemp.listaAdj[noAtual][i];
			else
				break;
		}
		
		removeAresta(<noAtual,noDestino>,GTemp);
		noAtual = noDestino;
	}
	
	return true;
			
	
}*/
	
