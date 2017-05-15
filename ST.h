typedef struct no no;
struct no {
  char palavra[50];
  int vez;
  no *esq, *dir;
};

void insere(no **r, char *word);
void printa(no *r);
