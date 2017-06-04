typedef struct no Tno;

struct no {
        struct Titem *i;
        long int altura;
        struct no *esq, *dir;
};
Ti *mais_frequente(int n, Tno *r);
void percorre_arvore(Tno *r, Ti *p, int n);
void OrganizaItem(Ti *i, Ti *p, int n);
void insere(Tno **r, char *word, int *numero, long int altura);
void printa(Tno *r);
void freeEveryOne(Tno **raiz);
void achaItem(Tno *raiz, char *word);
void printaArvore(Tno *raiz, int max, int maxi);
