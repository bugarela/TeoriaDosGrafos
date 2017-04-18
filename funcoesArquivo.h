#include <fstream>
#include "funcoesImpressao.h"
using namespace std;

void leGrafo(string grafo, Grafo *G){
	
	int no,conexao;
	char ch,op = '?';
	
	ifstream arquivo (grafo + ".txt");
	
    if (arquivo.is_open()){
        
        while(arquivo >> no){ // lê nós enquanto houverem linhas no arquivo
		
			arquivo >> ch;
			arquivo >> noskipws >> ch; 
			// noskipws = no skip whitespaces -> usado para verificar se houve quebra de linha
			
			vector<int> linha;
			linha.resize(0);
			
			while(ch != '\n'){ // lê conexões até uma quebra de linha
				
				arquivo >> conexao;
				linha.push_back(conexao); // coloca todas as conexoes em um vetor dinâmico "linha"
					
				arquivo >> noskipws >> ch;
			}
			
			G->listaAdj.push_back(linha); // insere o vetor com as conexoes na lista de adjacência
		}
		
        arquivo.close();
        
        cout << "Grafo " << grafo << " carregado." << endl;
        
	}
	
	int n = G->listaAdj.size();
	vector<int> lpesos;
	lpesos.resize(0);
	
	for(int j=0;j<n;j++)
		lpesos.push_back(1);
		
	for(int i=0;i<n;i++)
		G->pesos.push_back(lpesos); // preenche pesos com 1's
	
	ifstream arquivoP (grafo + "pesos.txt");
	
    if (arquivoP.is_open()){
    	
    	int a,b,peso;
        
        while(arquivoP >> a){ 
		
			arquivoP >> b >> peso;
			G->pesos[a][b] = peso;
		
		}
		
        arquivoP.close();
        
        cout << "Pesos de " << grafo << " carregados." << endl;
        
	}
	
	
}

void escreveGrafo(string grafo, Grafo G){
	
	ofstream saida (grafo + ".txt");
	
    if (saida.is_open()){
    	for(int no=0; no<G.listaAdj.size(); no++){
			saida << no << ":";
			for(int conexao : G.listaAdj[no])
				saida << " " << conexao;
			saida << endl;
		}
		saida.close();
	}
}

