typedef struct Titem Ti;
struct Titem {
        char palavra[50];
        long int vez;
};
void addItem(Ti **i, char *word);
int compara(Ti **i, char *word);
void printaItem(Ti *i);
char limpa(char l);
void adicionaVez(Ti **i);
