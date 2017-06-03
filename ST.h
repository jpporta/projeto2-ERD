typedef struct no Tno;

struct no {
        struct Titem *i;
        struct no *esq, *dir;
};
Ti *mais_frequente(int n, Tno *r);
void percorre_arvore(Tno *r, Ti *p, int n);
void OrganizaItem(Ti *i, Ti *p, int n);
void insere(Tno **r, char *word, int *numero);
void printa(Tno *r);
void freeEveryOne(Tno **raiz);
