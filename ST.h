typedef struct no Tno;

struct no {
        struct Titem *i;
        long int altura;
        struct no *esq, *dir;
};
typedef struct Tlista Tl;
struct Tlista {
        Ti *i;
        Tl *prox;
};
Ti *mais_frequente(int n, Tno *r);
void percorre_arvore(Tno *r, Ti *p, int n);
void OrganizaItem(Ti *i, Ti *p, int n);
void insere(Tno **r, char *word, int *numero, long int altura);
void printa(Tno *r);
void freeEveryOne(Tno **raiz, int tudo);
void achaItem(Tno *raiz, char *word);
void printaArvore(Tno *raiz, int max, int maxi);
long int vetorizaArvore(Tno *raiz, Tl **lista);
void balanceandoVetor(Tno **raiz, Tl *lista, long int tam);
void freeVetor(Tl **lista);
Tl* insereVetor(Tl **lista, Tno *raiz);
void criaArvoreBalanceada(Tno **raiz, Tl *lista, long int tam, long int altura);