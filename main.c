#include "arvore_expressao.h"
#include <stdio.h>


int main(void){

    char postfix[80] = ""; // o postfix
    
    //cria arvore de espressão
    avrExp* a = arv_criavazia();
    
    //passa postfix para arvore de expressao
    a = pfx_arvexp(postfix,a);
    //imprime arvore de expressao de forma aninhada
    arv_imprime(a);

    //calcula a expressao
    printf("%d", calculaExpressao(a));
    return 0;
}