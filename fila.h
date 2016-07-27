#ifndef QUEWE90

#define QUEWE90

class quewe{
	

	public:
		
		quewe(int tamanho){
			limite = tamanho;
			fila = new int[tamanho];
		}

		int back();//retorna o ultimo elemento da fila

		int front();//retorna o primeiro elemento da fila

		int pop();// remove o primeiro elemento da fila

		void push(int elemento);//insere 'elemento' na fila
			
		void queue();//esvazia a fila

		int size();// retorna o numero de elementos na fila


	private:
		int limite;
		int tamanho;
		int *fila; 
		int topo;
		int base;
		bool empty();//retorna true se a fila nao contem elementos, e, se nao, false
		bool full();//retorna true se a fila estiver cheia
};

#endif
