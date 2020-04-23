
struct avrExp{
    int tipo;
    int valor;
    char oper;
    struct avrExp* esq;
    struct avrExp*  dir;
};

typedef struct avrExp avrExp;


avrExp* arv_criavazia(void);
avrExp* arv_criaOperdor(int tipo,char oper, avrExp* esq, avrExp* dir );
avrExp* arv_criaOperando(int tipo,int valor, avrExp* esq, avrExp* dir );
int arv_vazia(avrExp* a);
int calculaExpressao(avrExp* a);
avrExp* arv_libera(avrExp* a);
void arv_imprime(avrExp* a);
avrExp* pfx_arvexp(char postfix[80], avrExp* a);