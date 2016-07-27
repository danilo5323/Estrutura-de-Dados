
#include <cstdlib>
#include <iostream>
#include "fila.h"
using std::cout;

int quewe::back(){
	return fila[topo];
}//retorna o ultimo elemento da fila

bool quewe::empty(){//retorna true se a fila nao contem elementos, e, se nao, false
	if(topo <= base+1)
		return true;
	else 
		return false;
}

bool quewe::full(){//retorna true se a fila estiver cheia
	if (topo - base >= limite)
		return true;
	else 
		return false;

}

int quewe::front(){//retorna o primeiro elemento da fila
	return fila[base+1];
}

int quewe::pop(){// remove o primeiro elemento da fila
	if(empty()){
		cout << "erro, operacao invalida, a fila esta vazia";
		exit (0);
	}
	int temp = fila[base];
	base++;
	return temp;
}

void quewe::push(int elemento){//insere 'elemento' na fila
	if(full()){
		cout << "erro, operacao invalida, a fila esta cheia";
		exit (0);
	}
	topo++;
	if(topo%tamanho == 0)
		fila[tamanho] = elemento;
	else
		fila[topo%tamanho] = elemento;
} 

void quewe::queue(){
	topo = base;
}//esvazia a fila

int quewe::size(){
	return topo-base;
}// retorna o numero de elementos na fila

