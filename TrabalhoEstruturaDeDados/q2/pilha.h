typedef struct pilha Pilha;

/*Fun��o que cria uma pilha*/
Pilha* pilha_cria(void);

/*Testa se uma pilha � vazia*/
int pilha_vazia(Pilha *p);

/*Fun��o que adiciona um elemento no topo de uma pilha*/
void pilha_push(Pilha *p, int info);

/*Fun��o que remove um elemento do topo de uma pilha*/
int pilha_pop(Pilha *p);

/*Fun��o que imprime os elementos de uma pilha*/
void pilha_imprime(Pilha *p);

/*Libera o espa�o alocado para uma pilha*/
void pilha_libera(Pilha *p);

/*fun��o que retorna o valor no topo de uma pilha*/
int topo(Pilha *p);

/*retorna a quantidade de elementos da pilha com valor impar*/
int impares(Pilha* p);

/*verifica os elementos pares de uma pilha e os empilha em ordem crescente em outra pilha*/
Pilha* empilha_pares(Pilha *p1, Pilha *p2);

