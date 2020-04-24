struct avrExp{
    int tipo;
    int valor;
    char oper;
    struct avrExp* esq;
    struct avrExp*  dir;
    struct avrExp* pai;
};
typedef struct avrExp avrExp;


avrExp* arv_criavazia(void);

int arv_vazia(avrExp* a);

avrExp* arv_libera(avrExp* a);

void arv_imprime(avrExp* a);

avrExp* arv_criaOperdor(int tipo,char oper, avrExp* esq, avrExp* dir, avrExp* pai);

avrExp* arv_criaOperando(int tipo,int valor, avrExp* esq, avrExp* dir, avrExp* pai);

int calculaExpressao(avrExp* a);

avrExp* busca_no(avrExp* a);

avrExp* pfx_arvexp(char* postfix, avrExp* a);


