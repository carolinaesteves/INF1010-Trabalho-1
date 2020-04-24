#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_vet.h"

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

int pilha_vazia (Pilha* p)
{
    if(p->topo == 0)
        return 1;
    return 0;
}

int pilha_tamanho(Pilha * p) {
	return p->topo;
}


void pilha_libera (Pilha* p)
{
    int i;
    //for(i=0; i < p->topo; i++)
    //    free(p->vet[i]);
    free(p);
}



char pilha_topo(Pilha * p) {
	if (p->topo == 0) {
		//printf("Pilha vazia");
		return -1;
	}
	return p->vet[p->topo-1];
}

void pilha_imprimir(Pilha * p) {
	int i;
	printf("[ ");
	for(i=0; i<p->topo; i++) {
		printf("%c ", p->vet[i]);
	}
	printf("]\n");
}

int precedencia_operador (char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;

    return 0;
}

void converte_infix_para_postfix (char* str, char* postfix)
{
    int i, j;
    // char postfix[120];
    Pilha* pilha = pilha_cria ();

    // for para andar até o final da string
    for (i=0, j = -1; i<strlen(str); ++i)
    {
        // ignora os espaços
        if(str[i]!=' ')
        {

            // se o símbolo for um número adiciona no buffer de saída
            if (str[i] >= '0' && str[i] <= '9')
            {

                postfix[++j] = str[i];

                if (str[i+1] >= '0' && str[i+1] <= '9')
                {
                    postfix[++j] = str[i+1];
                    postfix[++j] = ' ';
                    i++;
                }
                else
                    postfix[++j] = ' ';
            }
            // se o símbolo for (, adiciona na pilha
            else if (str[i] == '(')
                pilha_push(pilha,str[i]);
            // se o símbolo for )
            else if (str[i] == ')') 
            {
                // até o símbolo do topo da pilha ser (
                while(pilha_vazia(pilha)!=1 && pilha_topo(pilha)!='(')
                {
                    postfix[++j] = pilha_pop (pilha);
                    postfix[++j] = ' ';
                }
                pilha_pop (pilha);
            }
            else
            // se o símbolo for um operador
            {
                // enquanto existe um operador na pilha e se o operador da iteração tiver precedência
                // menor que o topo da pilha
                while(pilha_vazia(pilha)!=1 && precedencia_operador(str[i])<=precedencia_operador(pilha_topo(pilha)))
                {
                    // pop da pilha e adiciona no buffer de saída
                    postfix[++j] = pilha_pop (pilha);
                    postfix[++j] = ' ';
                }
                pilha_push(pilha,str[i]);
            }
        }

    }

    // enquanto houverem operadores na pilha, pop e insira no buffer de saída
    while (pilha_vazia(pilha)!=1)
    {
        postfix[++j] = pilha_pop (pilha);
        postfix[++j] = ' ';
    }

    postfix[++j] = '\0'; 
}