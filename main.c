#include "arvore_expressao.h"
#include <stdio.h>

int main(void){ 
    avrExp* a = arv_criavazia();
    //char postfix[80] = {'7','3','2','/','+','\0'}; // o postfix
    char postfix[80] = "2 3 - 1 + 2 2 - /";
    printf("Temos o seguinte postfix %s\n",postfix);
    
    //passa postfix para arvore de expressao
    // printf("Entrando na funcao de conversao: \n");
    a = pfx_arvexp(postfix,a);
    //imprime arvore de expressao de forma aninhada
    arv_imprime(a);

    //calcula a expressao
    printf("%d", calculaExpressao(a));
    return 0;
}