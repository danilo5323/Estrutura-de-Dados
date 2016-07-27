#include "methodsordenation.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ordenacoesbusca::menuordenacao(int vetor[]) {
	int esq = 1;
	int dir = length(vetor);
	int opcao;
	cout << " menu de ordenacao \n" 
	<< " 1 ordenar usando insertsort\n"
	<< " 2 ordenar usando bublesort\n"
	<< " 3 ordenar usando selectsort\n"
	<< " 4 ordenar usando quicktsort\n"
	<< " 5 ordenar usando mergesort\n"
	<< " 6 ordenar usando heapsort\n";
	
	cin >> opcao;
	switch (opcao) {
		case 1:
			insertsort(vetor);
			break;
		case 2:
			bubblesort(vetor);
			break;
		case 3:
			selectsort(vetor);
			break;
		case 4:
			quicksort(vetor);
			break;
		case 5:
			mergesort(esq, dir, vetor);
			break;
		case 6:
			heapsort(vetor);
			break;
		default:
			cout << "opcao invalida";
			return;
	}
	for (int i = 0; i < length(vetor); i++) {
	   cout << i + 1 << " - " << vetor[i] << '\n';
	}
}

void ordenacoesbusca::insertsort(int vetor[]) {
	int i, j, x;
	for (j = 1; j < length(vetor); ++j) {
		x = vetor[j];
		for (i = j - 1; i >= 1 && vetor[i] > x; --i) {
			vetor[i + 1] = vetor[i];
		}
		vetor[i + 1] = x;
	}
}

void ordenacoesbusca::selectsort(int vetor[]) {
	int i, j, min, x;
	for (i = 0; i < length(vetor) - 1; ++i) {
		min = i;
		for (j = i + 1; j < length(vetor); ++j) 
			if (vetor[j] < vetor[min]) 
				min = j;
		
		x = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = x;
	}
}

void ordenacoesbusca::bubblesort(int vetor[]) {
	int i, j;
	for (i = 0; i < length(vetor); i++) 
		for (j = i + 1; j < length(vetor); j++) 
			if (vetor[j] < vetor[i]) 
				troca(vetor, i, j);
}

void ordenacoesbusca::quicksort(int vetor[]) {
	int elements = length(vetor);
	quick(vetor, 0, elements - 1);
}

int ordenacoesbusca::quick(int vetor[], int left, int right) {
	if (right - left <= 0) {
		return 0;
	} else {
		int pivot = vetor[right];
		int partition2 = partition(vetor, left, right, pivot);
		quick(vetor, left, partition2 - 1);
		quick(vetor, partition2 + 1, right);
	}
	return 0;
}

int ordenacoesbusca::partition(int vetor[], int left, int right, int pivot) {
	int leftptr = left - 1;
	int rightptr = right;
	while (true) {
		while (vetor[++leftptr] < pivot) {
		}
		while (rightptr > 0 && vetor[--rightptr] > pivot) {
		}
		if (leftptr >= rightptr) {
			break;
		} else {
			troca(vetor, leftptr, rightptr);
		}
	}
	troca(vetor, leftptr, right);
	return leftptr;
}

void ordenacoesbusca::intercala(int p, int q, int r, int v[]) {
	int i, j, k;
	int *w = new int [r-p];
	
	i = p;
	j = q;
	k = 0;
	while (i < q && j < r) {
		if (v[i] <= v[j]) {
			w[k++] = v[i++];
		} else {
			w[k++] = v[j++];
		}
	}
	while (i < q) {
		w[k++] = v[i++];
	}
	while (j < r) {
		w[k++] = v[j++];
	}
	for (i = p; i < r; ++i) {
		v[i] = w[i - p];
	}
	delete w;
}


void ordenacoesbusca::heapsort(int vetor[]) {
	int tamanho = length(vetor) - 1;
	int p, m;
	for (p = tamanho / 2; p >= 1; --p) {
		heap(p, tamanho, vetor);
	}
	for (m = tamanho; m >= 2; --m) {
		troca(vetor, 1, m);
		heap(1, m - 1, vetor);
	}
}

void ordenacoesbusca::heap(int esq, int dir, int vetor[]) {
	int f = 2 * esq;
	int temp = vetor[esq];
	while (f <= dir) {
		if (f < dir && vetor[f] < vetor[f + 1]) {
			++f;
		}
		if (temp >= vetor[f]) {
			break;
		}
		vetor[esq] = vetor[f];
		esq = f;
		f = 2 * esq;
	}
	vetor[esq] = temp;
}







void ordenacoesbusca::mergesort(int esq, int dir, int vetor[]) {
	if (esq < dir - 1) {
		int q = (esq + dir) / 2;
		mergesort(esq, q, vetor);
		mergesort(q, dir, vetor);
		intercala(esq, q, dir, vetor);
	}
}

void ordenacoesbusca::troca(int dir, int esq){
	int temp = dir;
	dir = esq;
	esq = temp;
		
}

void ordenacoesbusca::troca(int vetor[], int dir, int esq) {
	int temp = vetor[dir];
	vetor[dir] = vetor[esq];
	vetor[esq] = temp;
}

int ordenacoesbusca::buscasequencial(int busca, int vetor[]){
	int  i;
	for (i=0; i < length(vetor); i++){
		if (vetor[i] == busca)
			return (i+1);
	}
	return -1;
}


int ordenacoesbusca::buscasequencialrecursiva(int busca, int vetor[]){
		int tamanho = length(vetor);
		return sequencialrecursiva(busca, tamanho, vetor );
}

int ordenacoesbusca::sequencialrecursiva( int busca, int pos , int vetor[]){
	if (busca == 0) 
		return -1;
	if (busca == vetor[pos-1])
		return pos -1;
	else
		return sequencialrecursiva(busca, --pos, vetor);
   

}



int ordenacoesbusca::buscabinaria(int busca, int vetor[]){    
	
	int esquerda, meio, direita;
	esquerda = 0;
	direita = length(vetor) -1;
	while (esquerda <= direita){
		meio = (esquerda + direita)/2;
		if (vetor[meio] == busca)
			return meio + 1;
		if (vetor[meio] < busca)
			esquerda = meio + 1;
		else 
			direita = meio -1;
	}
	return -1;
}

int ordenacoesbusca::buscabinariarecursiva(int busca, int vetor[]){
	return binariarecursiva(busca, 0, length(vetor) -1, vetor);
}

int  ordenacoesbusca::binariarecursiva(int busca, int inferior, int superior,int vetor[]){
	
	if (inferior > superior)
		return -1;
	else {
		int meio = (inferior + superior ) / 2;
		if (vetor[meio] == busca)
		   return meio + 1;
		if (vetor[meio]< busca)
			return (binariarecursiva(busca, meio+1, superior, vetor));
		else
			return (binariarecursiva(busca, inferior, meio -1, vetor));
	}
}

int ordenacoesbusca::length(int vetor[]){
	for (int i=0; ; i++) 
		if (vetor[i] < 0) 
			return i;
}
