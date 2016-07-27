
#include <cstdlib>
#include <iostream>
#include "MethodsOrdenation.h"
#include "MethodsOrdenation.cpp"
using namespace std;

int main(){

	int vetorTeste[] = {1,3,8,3,8,4,7,5,8,5,3,8,5,3,6,543,43,6,0,8,90,552,-3};

	OrdenacoesBusca ord;

	ord.menuOrdenacao(vetorTeste);

	int opcao, procura;

	cout <<  "digite um numero a ser localizado";
	cin >> procura;

	cout << "a busca sequencial do valor " << procura << " esta na posicao " << ord.buscaSequencial(procura , vetorTeste) << endl;
	// System.out.println("a busca sequencial Recursiva do valor " << procura << " esta na posicao " + ord.buscaSequencialRecursiva(procura, vetorTeste) << endl;
	cout <<  "a busca binaria do valor " << procura << " esta na posicao " << ord.buscaBinaria(procura, vetorTeste) << endl;
	cout <<  "a busca binaria recursiva do valor " << procura << " esta na posicao " << ord.buscaBinariaRecursiva(procura, vetorTeste) << endl;
	cout <<  "digite 1 para tentar novamente ";
	
	cin >> opcao;
	
	if (opcao ==1)
		main();
	return 0;
}

