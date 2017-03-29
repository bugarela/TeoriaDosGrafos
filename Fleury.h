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
		
	Grafo GTemp = G;
	
	int noAtual = 0;
	int noDestino = GTemp.listaAdj[noAtual][0]; 
	int i;
	
	while (noDestino != 0){
		
		i=0;
					
		while(ehPonte(<noAtual,noDestino>,G)){
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()<=i)
				noDestino=GTemp.listaAdj[noAtual][i-1];
			else
				break;
		}
		
		removeAresta(<noAtual,noDestino>,GTemp);
		GTemp.listaAdj.erase(GTemp.listaAdj.begin() + noInicial);
		noAtual = noDestino;
		
		if(GTemp.listaAdj[noAtual].size() == 0)
			return false;
		else
			noDestino = GTemp.listaAdj[noAtual][0];
	}
	
	return true;
			
	
}*/
	
