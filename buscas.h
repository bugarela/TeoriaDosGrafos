#include "Dijkstra.h"

vector<int> olhaFilhos(int noInicial, Grafo G, set<int>& restantes){
	vector<int> filhos;
	filhos.resize(0);
	
	for(int conexao : G.listaAdj[noInicial])
		if(restantes.find(conexao) != restantes.end()){
			filhos.push_back(conexao);
			restantes.erase(conexao);
		}
		
	return filhos;
}

vector<int> BFS(int noInicial, Grafo G){
	int n = G.listaAdj.size();
	set<int> restantes = set<int>();
	vector<int> fila;
	fila.resize(0);
	
	for(int i=0;i<n;i++){
		restantes.insert(i);
	}
	
	restantes.erase(noInicial);	
	fila.push_back(noInicial);
	
	if (!(busca(noInicial,G,restantes)).empty()){
		cout << "Grafo nao conexo a partir de " << noInicial << endl;
		return vector<int>();
	}
	
	int i=0;
	
	while(!restantes.empty()){

		vector<int> temp = olhaFilhos(fila[i],G,restantes);
		fila.insert(fila.end(), temp.begin(), temp.end()); // concatena
		i++;
			
	}
	
	return fila;
		
}

vector<int> DFS(int noInicial, Grafo G, set<int>& restantes){	
	
	vector<int> fila;
	fila.resize(0);
	
	restantes.erase(noInicial);	
	fila.push_back(noInicial);
	
		
	for(int conexao : G.listaAdj[noInicial]){
		if(restantes.find(conexao) != restantes.end()){
			restantes.erase(conexao);
			vector<int> temp = DFS(conexao,G,restantes);
			fila.insert(fila.end(), temp.begin(), temp.end()); // concatena
		}
	}
	
	
	return fila;
}

vector<int> DFS(int noInicial, Grafo G){
	int n = G.listaAdj.size();
	set<int> restantes = set<int>();
	
	for(int i=0;i<n;i++){
		restantes.insert(i);
	}
	
	if (!(busca(noInicial,G,restantes)).empty()){
		cout << "Grafo nao conexo a partir de " << noInicial << endl;
		return vector<int>();
	}
	
	return DFS(noInicial, G, restantes);
}




