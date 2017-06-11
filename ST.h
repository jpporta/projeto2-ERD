
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
void freeEveryOne(Tno **raiz, int tudo);
void achaItem(Tno *raiz, char *word);
void printa_altura(Tno *r, int n);
void printa_esq(Tno *r, int n, int alt, char *p);
void printa_dir(Tno *r, int n, int alt, char *p);
void freev(char *p, int n);

//Balancear arvore
long int altura(Tno *raiz);
int balancea( Tno *raiz );
Tno *rodaEsqEsq( Tno *raiz );
Tno *rodaEsqDir( Tno *raiz );
Tno *rodaDirEsq( Tno *raiz );
Tno *rodaDirDir( Tno *raiz );
Tno *balanceando( Tno *raiz );
