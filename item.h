typedef struct Titem Ti;
struct Titem {
        char palavra[50];
        int vez;
}
void addItem(Ti **i, char *word);
