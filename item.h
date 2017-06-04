typedef struct Titem Ti;
struct Titem {
        char palavra[100];
        long int vez;
};
void addItem(Ti **i, char *word);
int compara(Ti **i, char *word);
void printaItem(Ti *i);
char limpa(char l);
void adicionaVez(Ti **i);
void printaArq(Ti *i, FILE *out);
void printaItemPlus(Ti *i, long int altura);
