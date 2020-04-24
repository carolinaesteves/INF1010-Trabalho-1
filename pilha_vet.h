
#define TAM_MAX 100

typedef struct pilha {
    char topo;
    int vet[TAM_MAX]; 
} Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, char v);
char pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
int pilha_tamanho(Pilha * p);
void pilha_libera (Pilha* p);
char pilha_topo(Pilha * p);
void pilha_imprimir(Pilha * p);
void converte_infix_para_postfix (char* str, char* postfix);
