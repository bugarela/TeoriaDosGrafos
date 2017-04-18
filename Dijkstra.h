#include "Fleury.h"
using namespace std;

#define INFINITO 2147483647

void dijkstra(int noInicial, Grafo G){
	vector<int> estimativas;
	vector<int> precedentes;
	int n = G.listaAdj.size();
	estimativas.resize(n);
	precedentes.resize(n);
	
	for(int valor : estimativas)
		valor = INFINITO;
	
	set<int> restantes = set<int>();
	for(int i=0;i<n;i++)
		restantes.insert(i); 
	
	int noAtual = noInicial;
	int menorEstimativa;
	estimativas[noInicial] = 0;
	precedentes[noInicial] = noInicial;
	
	while(restantes.size() > 0){
		
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
	
	for(int i=0; i<n; i++)
		cout << i << " ";
	cout << endl;
	
	for(int estimativa : estimativas)
		cout << estimativa << " ";
	cout << endl;
	
	for(int precedente : precedentes)
		cout << precedente << " ";
	cout << endl;
	
	cout << endl;
	
}
