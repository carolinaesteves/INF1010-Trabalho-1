#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

typedef struct pilha {
    int topo;
    int vet[TAM_MAX]; 
} Pilha;

Pilha* pilha_cria ()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p==NULL) exit (1);
    p->topo = 0;
    return p;
}

void pilha_push (Pilha* p, char v)
{
    if (p->topo == TAM_MAX) {
        printf("Capacidade da pilha estourou.\n");
        exit(1); 
    }
    
    p->vet[p->topo] = v;
    p->topo++;
}

int pilha_vazia (Pilha* p)
{
    if(p->topo == 0)
        return 1;
    return 0;
}

char pilha_pop (Pilha* p)
{
    char v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); 
    }
    
    v = p->vet[p->topo-1];
    p->topo--;
    return v;
}

void pilha_imprimir(Pilha * p) {
	int i;
	printf("[ ");
	for(i=0; i<p->topo; i++) {
		printf("%c ", p->vet[i]);
	}
	printf("]\n");
}



char pilha_topo(Pilha * p) {
	if (p->topo == 0) {
		//printf("Pilha vazia");
		return -1;
	}
	return p->vet[p->topo-1];
}

int precedencia_operador (char c)
{
	if(c == '+' || c == '-')
		return 1;
	else if (c == 'x' || c == '/')
		return 2;

	return 0;
}


int main (void)
{
	int i, j;
	char str[] = "(2-3+1)/(2-2)";
	char* expressao;
	Pilha* pilha = pilha_cria ();
	
	// for para andar até o final da string
	for (i=0, j = -1; i<strlen(str); ++i)
	{
		// ignora os espaços
		if(str[i]!=' ')
		{
			// se o símbolo for um número adiciona no buffer de saída
			if (str[i] >= '0' && str[i] <= '9')
				str[++j] = str[i];
			// se o símbolo for (, adiciona na pilha
			else if (str[i] == '(')
				pilha_push(pilha,str[i]);
			// se o símbolo for )
			else if (str[i] == ')') 
			{
				// até o símbolo do topo da pilha ser (
				while(pilha_vazia(pilha)!=1 && pilha_topo(pilha)!='(')
					str[++j] = pilha_pop (pilha);
				pilha_pop (pilha);
			}
			else
			// se o símbolo for um operador
			{
				// enquanto existe um operador na pilha e se o operador da iteração tiver precedência
				// menor que o topo da pilha
				while(pilha_vazia(pilha)!=1 && precedencia_operador(str[i])<=precedencia_operador(pilha_topo(pilha)))
					// pop da pilha e adiciona no buffer de saída
					str[++j] = pilha_pop (pilha);
				pilha_push(pilha,str[i]);
			}
		}

	}

	// enquanto houverem operadores na pilha, pop e insira no buffer de saída
	while (pilha_vazia(pilha)!=1)
		str[++j] = pilha_pop (pilha);

	str[++j] = '\0'; 
    printf( "%s", str ); 
	
	return 0;
}