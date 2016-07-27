#ifndef MEtHODS_ORDENATION

#define MEtHODS_ORDENATION


class OrdenacoesBusca{

	public:
		int length(int vetor[]);
		void menuOrdenacao(int vetor[]);
	//metodos de ordenação
		void quickSort(int vetor[]);
		void insertSort(int vetor[]);
		void selectSort(int vetor[]);
		void bubbleSort(int vetor[]);
		void heapSort(int vetor[]);
		void mergeSort(int esq, int dir, int vetor[]);
	//metodos de busca
		int buscaSequencial(int busca, int vetor[]);
		int buscaSequencialRecursiva(int busca, int vetor[]);
		int buscaBinaria(int busca, int vetor[]);
		int buscaBinariaRecursiva(int busca, int vetor[]);
		
	private:
		int quick(int vetor[], int left, int right);
		int partition(int vetor[], int left, int right, int pivot);
		void intercala(int p, int q, int r, int v[]);
		void heap(int esq, int dir, int vetor[]);
		void troca(int dir, int esq);
		void troca(int vetor[], int dir, int esq);
		int SequencialRecursiva( int busca, int pos , int vetor[]);
		int BinariaRecursiva(int busca, int inferior, int superior,int vetor[]);
};


#endif
