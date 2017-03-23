#include "conexidade.h"
using namespace std;

Grafo removeAresta(pair<int,int> aresta, Grafo G){
	Grafo GTemp;
	GTemp.listaAdj = G.listaAdj;
	int a = aresta.first;
	int b = aresta.second;
	
	for(auto conexao : GTemp.listaAdj[a])
		if(conexao = b)
			GTemp.listaAdj[a].erase(GTemp.listaAdj[a].begin()+conexao);
	for(auto conexao : GTemp.listaAdj[b])
		if(conexao = a)
			GTemp.listaAdj[b].erase(GTemp.listaAdj[b].begin()+conexao);
			
	return GTemp;
}

bool ehPonte(pair<int,int> aresta, Grafo G){
	Grafo GTemp = removeAresta(aresta,G);
	if(!ehConexo(GTemp))
		return false;
	return true;
}

/*bool ehEuclidiano(Grafo G){
	if(!ehConexo(G))
		return false;
	
	int noAtual = 0;
	int noDestino = G.ListaAdj[0][0]; // grafo conexo, logo sabe-se que todos os nós tem ao menos uma conexão
	int i=0;
	
	while(ehPonte(<noAtual,noDestino>,G)){
		i++;
		if(G.ListaAdj[noAtual].size()>=i)
			noDestino=G.ListaAdj[noAtual][i];
		else
			
	
}*/
	
