#include "conexidade.h"
using namespace std;

void removeAresta(int a, int b, Grafo *G){
	// dada uma aresta conectando a e b
	
	if(!ehDirecionado(*G)){ 
		for(int i=0;i<G->listaAdj[b].size();i++)
			if(G->listaAdj[b][i] == a) // remove as conexões de b para a
				G->listaAdj[b].erase(G->listaAdj[b].begin()+i);
	}
	
	// se for não-direcionado, remove ambas direções. Se não, somente de a para b.
	
	for(int i=0;i<G->listaAdj[a].size();i++)
		if(G->listaAdj[a][i] == b) // remove as conexões de a para b
			G->listaAdj[a].erase(G->listaAdj[a].begin()+i);
	

}

bool ehPonte(int a, int b, Grafo G){
	// verifica se uma aresta de a para b é ponte, removendo a aresta e verificando se o grafo permanece conexo.
	Grafo GTemp = G;
	removeAresta(a,b,&GTemp);
	if(ehConexo(GTemp))
		return false;	
	return true;
}

bool ehEuleriano(Grafo G){
			
	for(int no=0;no<G.listaAdj.size();no++) // se dIn != dOut para algum nó, não há ciclo Euleriano
		if(grauEntrada(no,G) != grauSaida(no,G))
			return false;
		
	Grafo GTemp = G;
	
	for(int i=0;i<GTemp.listaAdj.size();i++) // remove possíveis nós desconexos (sem arestas conectadas a ele)
		if(GTemp.listaAdj[i].size()==0)
			removeNo(i,&GTemp);
	
	if(GTemp.listaAdj.size()==0) // se estiver vazio, retorna falso
		return false;
		
	int noAtual = 0;
	int noDestino = GTemp.listaAdj[noAtual][0]; // primeira aresta analisada é a do nó 0 para sua primeira conexão
	int i;
	
	while (noDestino != 0){
		
		if(GTemp.listaAdj[noAtual].size() == 0) // se o noAtual não tem mais conexões, o algoritmo para
			return false;
		else
			noDestino = GTemp.listaAdj[noAtual][0]; // se não, analisa a próxima conexão possível
		
		i=0;
					
		while(ehPonte(noAtual,noDestino,G) || noDestino == 0){ // evita pontes e voltar ao nó incial enquanto possível
			
			i++;
			
			if(GTemp.listaAdj[noAtual].size()>i) // se tiver outra opção
				noDestino=GTemp.listaAdj[noAtual][i]; // tenta com ela
			else 								// se não, desiste
				break;
		}
		
		removeAresta(noAtual,noDestino,&GTemp); // remove a aresta escolhida
		
		if(GTemp.listaAdj[noAtual].size() == 0 && noAtual != 0){ // se o nó ficar desconexo e não for o nó inicial, remove ele
			
			removeNo(noAtual,&GTemp);
			
			if(noAtual < noDestino)		
				noDestino--;
			// como o algoritmo de remover nó decrementa o índice dos nós maiores que ele, corrigimos o valor de noDestino.
		}
	
		noAtual = noDestino;
	
	}
	
	for(auto lista : GTemp.listaAdj) // se ainda houverem arestas, o ciclo encontrado não é euleriano
		if(lista.size()>0)
			return false;
			
	
	return true;
			
	
}	
