#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_vet.h"

#define TAM_MAX 100

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
	char str[120] = "16/4x(4)";
	char postfix[120];
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
    printf( "%s", postfix ); 
	
	return 0;
}