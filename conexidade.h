#include <set>
#include "funcoesArquivo.h"
using namespace std;

set<int> busca(int noInicial, Grafo G, set<int> nosRestantes){
	nosRestantes.erase(noInicial);
	if(nosRestantes.empty())
		return nosRestantes;
	
	for(auto conexao : G.listaAdj[noInicial]){
		if(nosRestantes.find(conexao) != nosRestantes.end()){
			nosRestantes.erase(conexao);
			if(busca(conexao,G,nosRestantes).empty())
				return set<int>();
		}
	}
	
	return nosRestantes;
}

bool ehConexo(Grafo G){
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
		
	return (busca(0,G,nosRestantes)).empty();
}

int qtdComponentes(Grafo G){
	int componentes = 0;
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
		
	int noInicial = *nosRestantes.begin(); // primeiro no no set
	
	while(!(nosRestantes.empty())){ // enquanto o retorno de "busca" não é vazio
		nosRestantes = busca(noInicial,G,nosRestantes);
		noInicial = *nosRestantes.begin();
		componentes++;
	}
	
	return componentes;
}
