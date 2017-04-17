/* Esse trabalho contém funcionalidades do c++11, portanto precisa ser compilado com o comando -std=c++11 (pode ser adicionado em "Compiler Options" na IDE, ou adicionado a linha de comando no terminal */

#include <iostream>
#include <vector>
#include "Fleury.h"

using namespace std;

int main(){
	int no,conexao;
	char ch;
	int op = 1;
	
	Grafo G1, G2;
	
	G1.listaAdj.resize(0);
	G2.listaAdj.resize(0);
	
	leGrafo("G1",&G1);
	leGrafo("G2",&G2);
	
	/* Inicializa as outras estruturas de dados para G1 */
	inicializaMatrizAdj(&G1);
	inicializaListaArestas(&G1);
	inicializaMatrizInc(&G1);
	
	/* Se houver G2, inicializa as outras estruturas */
	if(G2.listaAdj.size()>0){
				
		inicializaMatrizAdj(&G2);
		inicializaListaArestas(&G2);
		inicializaMatrizInc(&G2);
		
	}
	
	/* Interação do menu em loop */
	while(op != 0){
		mostraMenu();
		fflush(stdin);
		cin >> op;
		switch (op){
			case 1:
				cout << "Matriz de Adjacencia: " << endl;
				imprimeMatriz(G1.matrizAdj);
				break;
			case 2:
				cout << "Lista de Adjacencia: " << endl;
				imprimeListaAdj(G1);
				break;
			case 3:
				cout << "Grau de cada no:" << endl;	
				imprimeGrauDeCadaNo(G1);
				break;
			case 4:
				insereNo(&G1);
				cout << "No inserido!" << endl;	
				break;
			case 5:
				int no;
				cout << "No a ser removido: ";
				fflush(stdin);
				cin >> no;
				removeNo(no,&G1);
				cout << "No removido!" << endl;	
				break;
			case 6:
				cout << "Matriz de Adjacencia do complemento de G1: " << endl;
				imprimeComplemento(G1);
				break;
			case 7:
				cout << "Matriz de Incidencia: " << endl;
				imprimeMatriz(G1.matrizInc);
				break;
			case 8:
				cout << "Lista de Arestas: " << endl;
				imprimeListaArestas(G1);
				break;
			case 9:
				cout << (ehConexo(G1) ? "G1 - conexo" : "G1 - nao conexo") << endl;
				break;
			case 10:
				cout << "Quantidade de Componentes: " << qtdComponentes(G1) << endl;
				break;
			case 11:
				cout << (ehEuleriano(G1) ? "Euleriano" : "Nao-Euleriano") << endl;
				break;
				
		}
	}
	
	/* Salva alterações */
	escreveGrafo("G1",G1);
		
	return 0;
}
