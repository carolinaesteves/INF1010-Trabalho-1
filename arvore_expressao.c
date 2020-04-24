#include "arvore_expressao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


avrExp* arv_criavazia(void){
    return NULL;
}

int arv_vazia(avrExp* a){
    return (a == NULL);
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
        if(a->tipo == 1){ //se for operador
            printf("(%c",a->oper);
            arv_imprime(a->esq);
            arv_imprime(a->dir);
            printf(")");
        }
        else{ //se não é operador então é um número
            printf("(%d",a->valor);
            arv_imprime(a->esq);
            arv_imprime(a->dir);
            printf(")");
        }
    }
    else
        printf("() ");
}

avrExp* arv_criaOperador(int tipo,char oper, avrExp* esq, avrExp* dir, avrExp* pai ){
    avrExp* a = (avrExp*) malloc(sizeof(avrExp));
    if(a == NULL)
        exit(1);

    a->tipo = 1;
    a->oper = oper;
    a->esq = esq;
    a->dir = dir;
    a->pai = pai;
    return a;
}

avrExp* arv_criaOperando(int tipo,int valor, avrExp* esq, avrExp* dir, avrExp* pai ){
    avrExp* a = (avrExp*) malloc(sizeof(avrExp));
    if(a == NULL)
        exit(1);

    a->tipo = 0;
    a->valor = valor;
    a->esq = esq;
    a->dir = dir;
    a->pai = pai;
    return a; 
}

int calculaExpressao(avrExp* a){
    if((a == NULL) || ((a->tipo != 0) && (a->tipo != 1 )))
        return 0;
    else if(a->tipo == 0) //verifica se é operando
        return a->valor;
    else{
        switch (a->oper)
        {
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
            if (calculaExpressao(a->dir) == 0)
                printf("Divisao por 0. Equacao nao e valida.\n");
            else
                return calculaExpressao(a->esq) / calculaExpressao(a->dir);
            break;
        }
    }
    return 0;
}

avrExp* busca_no(avrExp* a){
    avrExp* aux = a;
    avrExp* p = aux->pai;
    while(p->dir != NULL && p->esq != NULL) //enquanto o pai não puder ter mais filhos
    {
        //buscar nos avos
        aux = p;
        p = p->pai;
    }
    return p;
}

avrExp* pfx_arvexp(char* postfix, avrExp* a){
    int t;
    avrExp* atual;
    avrExp* novo;
    t = strlen(postfix);

    //verifica se esse elemento se é operador ou operando, cria um nó para ele e coloca na raíz;
    switch (postfix[t-2]) //pega o elemento do postfix mais a direita
    {
    case '+':
        a = arv_criaOperador(1,'+',arv_criavazia(),arv_criavazia(),arv_criavazia());
        break;
    case '-':
        a = arv_criaOperador(1,'-',arv_criavazia(),arv_criavazia(),arv_criavazia());
        break;
    case '*':
        a = arv_criaOperador(1,'*',arv_criavazia(),arv_criavazia(),arv_criavazia());
        break;
    case '/':
        a = arv_criaOperador(1,'/',arv_criavazia(),arv_criavazia(),arv_criavazia());
        break;
    default:
        if(postfix[t-2] != ' '){ //ignorar espaço
                if(postfix[t-3] != ' '){  //verifica anterior
                    // -48 para converter da tabela ascii para número int
                    int res = ((int)postfix[t-3]-48 )* 10;
                    res += (int)postfix[t-2]-48;
                    novo = arv_criaOperando(0,res,arv_criavazia(),arv_criavazia(),arv_criavazia());
                }
                else{
                    novo = arv_criaOperando(0,(int)postfix[t-1]-48,arv_criavazia(),arv_criavazia(),arv_criavazia());
                }
            }
            break;
    }
    atual = a;

    for(int i=t-3;i>=0;i--)
    { //para cada elemento da direita p/esquerda com exceção do último
        switch (postfix[i])
        {  //crie um nó
            case '+':
                novo = arv_criaOperador(1,'+',arv_criavazia(),arv_criavazia(),arv_criavazia());
                break;
            case '-':
                novo = arv_criaOperador(1,'-',arv_criavazia(),arv_criavazia(),arv_criavazia());
                break;
            case '*':
                novo = arv_criaOperador(1,'*',arv_criavazia(),arv_criavazia(),arv_criavazia());
                break;
            case '/':
                novo = arv_criaOperador(1,'/',arv_criavazia(),arv_criavazia(),arv_criavazia());
                break;
            default:
                if(postfix[i] != ' ')
                { //ignorar espaço
                    if(postfix[i-1] != ' ' && i-1>=0)
                    {  //verifica anterior
                        int res = ((int)postfix[i-1]-48 )* 10;
                        res += (int)postfix[i]-48;
                        novo = arv_criaOperando(0,res,arv_criavazia(),arv_criavazia(),arv_criavazia());
                        i--;
                    }
                    else{
                        novo = arv_criaOperando(0,(int)postfix[i]-48,arv_criavazia(),arv_criavazia(),arv_criavazia());
                    }
                    
                }

                break;
            }

        if(postfix[i] != ' ')
        {
            // se o nó atual não tem filho a direita
            if (atual->dir == NULL)
            {
                atual->dir = novo;
                novo->pai = atual;
            }
            // se o nó atual não tem filho a esquerda
            else if (atual->esq == NULL)
            {
                atual->esq = novo;
                novo->pai = atual;
            }
            // se o nó atual já tem duas subarvores, procurar o nó disponivel
            else
            {
                atual = busca_no(atual);
                if (atual->dir == NULL)
                {
                    atual->dir = novo;
                    novo->pai = atual;
                }
                else if (atual->esq == NULL)
                {
                    atual->esq = novo;
                    novo->pai = atual;
                }
            }   
        // se o novo nó é um numero
        if (novo->tipo == 0)
            atual = novo->pai;
        else
            atual = novo;
    }
}

    
    return a;
        
}
