#include <set>
#include "funcoesArquivo.h"
using namespace std;

set<int> busca(int noInicial, Grafo G, set<int> nosRestantes){
	// verifica quantos nós NÃO são alcançados a partir de um noInicial
	
	nosRestantes.erase(noInicial); // noInicial alcançado, portanto não é restante
	
	if(nosRestantes.empty())
		return nosRestantes; // se não há nós restantes, retorna vazio
	
	for(auto conexao : G.listaAdj[noInicial]){ // para cada conexao de noInicial
		if(nosRestantes.find(conexao) != nosRestantes.end()){ // se a conexão estiver em nosRestantes
			nosRestantes.erase(conexao); // apaga a conexao de nosRestantes
			nosRestantes = busca(conexao,G,nosRestantes); // chama recursivamente a funcao iniciando naquele nó
		}
		if(nosRestantes.empty()) // se nosRestantes está vazio
			return set<int>(); // retorna vazio
		// senão, continua
		
	}
	
	return nosRestantes; // retorna o conjunto de nos que não foi alcançado
}

bool ehConexo(Grafo G){
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
	
	// insere todos os nós em um set (árvore binária)
	// chama a função busca começando do nó 0, tendo que chegar em todos os nós
		
	return (busca(0,G,nosRestantes)).empty(); // se o retorno for vazio, não há elementos desconexos
}

int qtdComponentes(Grafo G){
	int componentes = 0, noInicial;
	set<int> nosRestantes;
	
	for(int i=0; i<G.listaAdj.size(); i++)
		nosRestantes.insert(i);
	
	// insere todos os nós em um set (árvore binária)
	
	while(!(nosRestantes.empty())){ // enquanto há nós a serem visitados
		
		noInicial = *nosRestantes.begin(); // primeiro nó entre os restantes
		nosRestantes = busca(noInicial,G,nosRestantes); // faz uma nova busca
		
		componentes++; // aumenta o número de componentes para cada busca feita
	}
	
	return componentes;
}
