#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


void addItem(Ti **i, char *word) { // adiciona item ao no da arvore
  (*i) = (Ti *)malloc(sizeof(Ti));
  strcpy((*i)->palavra, word);
  (*i)->vez = 1;
}
// compara se a palavra eh maior menor ou igual a do no
int compara(Ti **i, char *word) {
  if (strcmp((*i)->palavra, word) == 0) {
    return 0;
  }
  if (strcmp((*i)->palavra, word) > 0)
    return 1;

  return -1;
}
void adicionaVez(Ti **i) { (*i)->vez++; } // aumenta a frequencia da palavra
void printaItem(Ti *i) {
  printf("%li ", i->vez);
  puts(i->palavra);
}
void printaArq(Ti *i, FILE *out) {
  fprintf(out, "%li ", i->vez);
  fputs(i->palavra, out);
  fprintf(out, "\n");
}
char limpa(char l) { // limpa uma palavra recebida, transformando-a em
                     // somente letras
  if ((int)l < 65 || ((int)l > 90 && (int)l < 97) || (int)l > 122) {
    return '\0';
  }
  return l;
}
void printaItemPlus(Ti *i, long int altura){
  printf("%li %s %li __\n", i->vez, i->palavra, altura);
}
