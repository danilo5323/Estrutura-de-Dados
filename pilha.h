

#ifndef STACKLD
#define STACKLD

#include <iostream>

class pilhaep{
	public:
		pilhaep(int tamanho);
		void empilha(int entrada);//insere um novo elmeento na pilha
		int remove();//retorna determinado item da fila e o remove
		void vazia();//verifica se a pilha esta vazia
		int consulta();//consulta o ultimo item da pilha
		void limpa();//limpa a pilha;
	private:
		int topo = 0;
		int TAMANHO_VETOR;
		int *pilha;
		
};

#endif 
