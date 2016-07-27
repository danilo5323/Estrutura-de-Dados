
#include "pilha.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;


void pilhaep::empilha(int entrada){// insere um novo valor a fila;
	if (topo <= TAMANHO_VETOR){
		topo ++;
		pilha[topo] = entrada;
	}
	else{
		cout << "lista cheia";
		exit (1);
	}
} 

int pilhaep::remove(){
	if (topo > 0){
		int temp = pilha[topo];
		topo--;	
		return temp;
	}
	else{ 
		cout << "pilha vazia";
		exit (1);
	}
}

void pilhaep::vazia(){
	if (topo == 0){
		cout << "lista vazia";
		exit (1);
	}
	else 
		cout << "a lista contem" << topo << "elementos";
		
}

int pilhaep::consulta(){
	if( pilha > 0)
		return pilha[topo];
	else 
		return 1;
}

void pilhaep::limpa(){
	topo = 0;
}

	
pilhaep::pilhaep(int tamanho){
	pilha = (int*) malloc( tamanho * sizeof(int));
	TAMANHO_VETOR = tamanho;
}
