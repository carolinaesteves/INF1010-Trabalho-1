#include "arvore_expressao.h"
#include <stdio.h>

int main(void){ 
    avrExp* a = arv_criavazia();
    char postfix[80] = {'7','3','2','/','+','\0'}; // o postfix
    
    //passa postfix para arvore de expressao
    a = pfx_arvexp(postfix,a);
    //imprime arvore de expressao de forma aninhada
    arv_imprime(a);

    //calcula a expressao
    printf("%d", calculaExpressao(a));
    return 0;
}