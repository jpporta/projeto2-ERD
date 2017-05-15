typedef struct no Tno;

struct no {
        struct Titem *i;
        struct no *esq, *dir;
};

void insere(Tno **r, char *word);
void printa(Tno *r);
