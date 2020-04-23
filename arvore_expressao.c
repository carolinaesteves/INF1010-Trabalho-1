#include "arvore_expressao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


avrExp* arv_criavazia(void){
    return NULL;
}

avrExp* arv_criaOperador(int tipo,char oper, avrExp* esq, avrExp* dir ){
    avrExp* a = (avrExp*) malloc(sizeof(avrExp));
    if(a == NULL)
        exit(1);

    a->tipo = 1;
    a->valor = -1; //O QUE COLOCAR AQUI?
    strcpy(a->oper,oper);
    a->esq = esq;
    a->dir = dir;
    return a;
}

avrExp* arv_criaOperando(int tipo,int valor, avrExp* esq, avrExp* dir ){
    avrExp* a = (avrExp*) malloc(sizeof(avrExp));
    if(a == NULL)
        exit(1);

    a->tipo = 0;
    a->valor = valor;
    strcpy(a->oper,"");// O QUE COLOCAR AQUI?
    a->esq = esq;
    a->dir = dir;
    return a; 
}

int arv_vazia(avrExp* a){
    return (a == NULL);
}

int calculaExpressao(avrExp* a){

   if((a == NULL) || (a->tipo != 0) && (a->tipo != 1 ))
    return 0;
    else if(a->tipo == 0) //verifica se é operando
        return a->valor;
    else{
        switch (a->oper){
            case '+':
                return calculaExpressao(a->esq) + calculaExpressao(a->dir);
                break;
            case '-':
                return calculaExpressao(a->esq) - calculaExpressao(a->dir);
                break;
            case '*':
                return calculaExpressao(a->esq) * calculaExpressao(a->dir);
                break;
             case '/':
                return calculaExpressao(a->esq) / calculaExpressao(a->dir);
                break;
        }
    }
}

avrExp* arv_libera(avrExp* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);        
    }
    return NULL;
}

void arv_imprime(avrExp* a){
    if(!arv_vazia(a)){
        //se não for operador
            printf("(%c",a->oper);
        //se não é operador então é um número
            printf("%d",a->valor);
            arv_imprime(a->esq);
            arv_imprime(a->dir);
            printf(")");
    }
    else
        printf("() ");
}