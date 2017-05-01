#include "Fleury.h"
using namespace std;

#define INFINITO 2147483647

bool dijkstra(int noInicial, Grafo G){
	vector<int> estimativas;
	vector<int> precedentes;
	int n = G.listaAdj.size();
	estimativas.resize(n);
	precedentes.resize(n);

	set<int> restantes = set<int>();
	for(int i=0;i<n;i++){
		estimativas[i] = INFINITO;
		precedentes[i] = -1;
		restantes.insert(i);
	}
	
	if (!(busca(noInicial,G,restantes)).empty())
		return false;	
	
	int noAtual = noInicial;
	int menorEstimativa;
	estimativas[noInicial] = 0;
	precedentes[noInicial] = noInicial;
	
	while(!restantes.empty()){
		
		for(int noDestino : G.listaAdj[noAtual])
			if(restantes.find(noDestino) != restantes.end())
				if(estimativas[noAtual] + G.pesos[noAtual][noDestino] < estimativas[noDestino]){
					estimativas[noDestino] = estimativas[noAtual] + G.pesos[noAtual][noDestino];
					precedentes[noDestino] = noAtual;
				}		
		
		restantes.erase(noAtual);
		
		menorEstimativa = INFINITO;
		for(auto it=restantes.begin(); it!=restantes.end(); ++it){
			if(estimativas[*it] < menorEstimativa){
				menorEstimativa = estimativas[*it];
				noAtual = *it;
			}
		}
			
	}
	
	cout << endl;
	cout << "\tNos: \t";
	for(int i=0; i<n; i++)
		cout << i << " ";
	cout << endl;
	
	cout << "Estimativas: \t";
	for(int estimativa : estimativas)
		cout << estimativa << " ";
	cout << endl;
	
	cout << "Precedentes: \t";
	for(int precedente : precedentes)
		cout << precedente << " ";
	cout << endl;
	
	cout << endl;
	
	return true;
	
}
