#include <iostream>
#include "grafo.h"
using namespace std;

bool compara(Aresta a, Aresta b){
	return a.peso < b.peso; 
}
// A lista de Adjacencia é inicializada na leitura do arquivo (ver funcao main), e as outras estruturas sao inicializadas a partir dela.

void inicializaMatrizAdj(Grafo *G){
	
	int nNos = G->listaAdj.size(); // mesmo tamanho da lista
	
	G->matrizAdj.resize(nNos);
	for(int i=0; i<nNos; i++)
		G->matrizAdj[i].resize(nNos); // redimensiona e zera a matriz
		
	
	for(int no=0; no<nNos; no++){
		vector<int> linha = G->listaAdj[no];
	
		for(int conexao : linha)
			G->matrizAdj[no][conexao]++; // incrementa para cada conexao do no
			
	}
}

bool ehDirecionado(Grafo G){ // verifica se o grafo G do arquivo é direcionado ou não.
	int tamanho = G.matrizAdj.size();
	if(tamanho == 0){
		cout << "Matriz nao inicalizada" << endl;
		return false;
	}
	
	for(int i=0; i<tamanho; i++)
		for(int j=i+1; j<tamanho; j++)
			if(G.matrizAdj[i][j] != G.matrizAdj[j][i]) // se a matriz nao é simétrica, então G é direcionado.
				return true;
				
	return false;	
}

void inicializaListaArestas(Grafo *G){
	int nNos = G->listaAdj.size();
	G->listaArestas.resize(0);
	
	// A Lista de Arestas é uma lista de pares, onde o primeiro elemento do par é o vértice de saída e o segundo é o vértice de entrada
	
	Aresta aresta;
	
	if(ehDirecionado(*G)){ // Caso G seja direcionado, todas as conexoes formam arestas únicas
	
		for(int i=0; i<nNos; i++)
			for(int j=0; j<G->listaAdj[i].size(); j++){ // cria uma aresta com cada conexao de cada nó na lista de adjacência, e coloca a aresta na lista
				aresta.x = i;
				aresta.y = G->listaAdj[i][j];
				aresta.peso = G->pesos[i][aresta.y];
				G->listaArestas.push_back(aresta);
			}
	
	} else { // Caso G seja não-direcionado, olhamos apenas a parte superior da matriz de adjacência, ou teríamos arestas repetidas
		
		for(int i=0; i<nNos; i++)
			for(int j=i; j<nNos; j++){
				for(int k=0;k<G->matrizAdj[i][j];k++){ // cria uma aresta para cada conexao da matriz de adjacencia, e coloca a aresta na lista
					aresta.x = i;
					aresta.y = j;
					aresta.peso = G->pesos[i][aresta.y];
					G->listaArestas.push_back(aresta);
				}
			}
	}
				
}

void inicializaMatrizInc(Grafo *G){
	
	int nNos = G->listaAdj.size();
	int nArestas = G->listaArestas.size();
	
	G->matrizInc.resize(nArestas); // redimensionando a matriz de Incidência: número de linhas é o número de arestas, número de colunas em cada linha é o número de nós do grafo
	for(int i=0; i<nArestas; i++)
		G->matrizInc[i].resize(nNos);
		
	int nSaida;
	if(ehDirecionado(*G)) // se for direcionado, preenchemos com -1 e 1. Caso não, só incrementamos 1.
		nSaida = -1;
	else
		nSaida = 1;
	
	for(int i=0;i<nArestas;i++){ // para cada aresta na lista, preenche uma linha da matriz com as conexões
		G->matrizInc[i][G->listaArestas[i].x]++;
		G->matrizInc[i][G->listaArestas[i].y]+=nSaida;		
	}
}

int grauEntrada(int no, Grafo G){
	int dIn = 0;
	
	for(int i=0;i<G.matrizAdj.size();i++)
			dIn += G.matrizAdj[i][no];
		
	return dIn;
}

int grauSaida(int no, Grafo G){
	return G.listaAdj[no].size();
}

int grauNo(int no, Grafo G){
	
	if(!ehDirecionado(G)) // se não for direcionado, retorna o número de conexões daquele nó
		return G.listaAdj[no].size(); // quantas conexões o nó tem é o mesmo que o número de elementos referentes a ele na lista de adjacencia (que seria a mesma coisa que a soma da linha da matriz)
		
	return (grauEntrada(no,G) + grauSaida(no,G)); // se não, calcula o grau de entrada mais o de saída
	
	
}

void insereNo(Grafo *G){
	char cmanter='?', ch = '?'; // variáveis para a entrada de dados
	bool manter = false;
	
	int conexao, no = G->listaAdj.size();
	cout << "Criando no " << no << ". Digite as conexoes: ";
	fflush(stdin);
	
	vector<int> linha;
	linha.resize(0);
	
	while(ch != '\n'){ // lê até uma quebra de linha
	
		cin >> conexao;
		linha.push_back(conexao);
			
		cin >> noskipws >> ch; // noskipws = no skip whitespaces -> usado para verificar se houve quebra de linha
	}
	
	G->listaAdj.push_back(linha); // insere o novo nó na lista
		
	if(!ehDirecionado(*G)){
		cout << "Conexoes bidirecionais? <1 - Sim, 0 - Nao>: "; // o usuário pode escolher manter o grafo direcionado, fazendo uma unica inserção com conexões bidirecionais
		cin >> cmanter;
		if (cmanter=='1')
			manter = true;
		else
			manter = false;
	}
	
	for(int i=0; i<no; i++) // insere uma coluna vazia (ou seja, um 0 ao final de cada linha da matriz)
		G->matrizAdj[i].push_back(0); 
		
	if(manter){
		for(int conexao : linha){
			G->listaAdj[conexao].push_back(no); // cria uma conexao dos nós antigos para o novo nó para cada conexao inserida, tanto na matriz quanto na lista
			G->matrizAdj[conexao][no]++;
		}
	}
	
	vector<int> linhaM;
	linhaM.resize(no+1);
	
	for(int conexao : linha) // insere as novas conexões em uma linha de matriz
		linhaM[conexao]++; 
	
	G->matrizAdj.push_back(linhaM); // insere a linha no final da matriz
	
}

void removeNo(int no, Grafo *G){
	
	// remove da matriz
	G->matrizAdj.erase(G->matrizAdj.begin() + no); // apaga linha
	
	for (int i=0;i<G->matrizAdj.size();i++) // apaga coluna (n-ésimo elemento de cada linha)
		G->matrizAdj[i].erase(G->matrizAdj[i].begin() + no);
	
	// remove da lista
	
	G->listaAdj.erase(G->listaAdj.begin() + no); // remove a linha referente ao nó
	
	for(int i=0;i<G->listaAdj.size();i++)
		for(int j=0;j<G->listaAdj[i].size();j++){
			if(G->listaAdj[i][j] == no) // remove as conexões para aquele nó
				G->listaAdj[i].erase(G->listaAdj[i].begin() + j);
			else if (G->listaAdj[i][j] > no) // decrementa os nós com índice maior que o nó removido para manter a consistência
				G->listaAdj[i][j]--;
		}
}
