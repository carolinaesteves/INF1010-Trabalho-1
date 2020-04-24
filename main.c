// 1512690 - Ana Carolina Esteves
// 1512996 - Anna Carolina Fonseca Buarque de Verçosa

#include <stdio.h>
#include "arvore_expressao.h"
#include "pilha_vet.h"

int main(void){ 
    avrExp* a = arv_criavazia();
    char postfix[80];
    char str[80];
    char temp;

    printf("Insira a expressao a ser calculada:");
    scanf("%[^\n]",str);

    converte_infix_para_postfix (str, postfix);

    //passa postfix para arvore de expressao
    a = pfx_arvexp(postfix,a);

    //calcula a expressao
    printf("Resultado da expressao: %d", calculaExpressao(a));
    return 0;
}