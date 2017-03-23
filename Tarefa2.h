#include <vector>
#include <set>
#include "funcoesArquivo.h"
using namespace std;

bool busca(int noInicial, Grafo G, set<int> nosRestantes){
	if(nosRestantes.empty())
		return true;
	
	for(auto conexao : G.listaAdj[noInicial]){
		if(nosRestantes.find(conexao) != nosRestantes.end()){
			nosRestantes.erase(conexao);
			if(busca(conexao,G,nosRestantes))
				return true;
		}
	}
	
	return false;
}

bool ehConexo(Grafo G){
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
		
	return (busca(0,G,nosRestantes));
}
