#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"


// insere no a arvore
void insere(Tno **r, char *word, int *numero, long int altura) {
  int i;
  if (*r == NULL) {
    *r = (Tno *)malloc(sizeof(Tno));
    addItem(&(*r)->i, word);
    *numero = *numero + 1;
    (*r)->esq = NULL;
    (*r)->dir = NULL;
    (*r)->altura = altura + 1;
  } else {
    i = compara(&(*r)->i, word);
    if (i > 0)
      insere(&(*r)->esq, word, numero, (*r)->altura);
    else if (i < 0)
      insere(&(*r)->dir, word, numero, (*r)->altura);
    else adicionaVez(&((*r)->i));
  }
}

Ti *mais_frequente(int n, Tno *r) {
  int i;
  Ti *p;
  p = malloc(n * sizeof(Ti));
  for (i = 0; i < n; i++) {
    strcpy(p[i].palavra, "NULL");
    p[i].vez = 0;
  }
  percorre_arvore(r, p, n);
  return p;
}
void percorre_arvore(Tno *r, Ti *p, int n) {
  if (r) {
    if (r->esq)
      percorre_arvore(r->esq, p, n);

    OrganizaItem(r->i, p, n);
    if (r->dir)
      percorre_arvore(r->dir, p, n);
  }
}
void OrganizaItem(Ti *i, Ti *p, int n) {
  int k, j;
  Ti aux, aux2;
  aux2 = *i;
  for (k = 0; k < n; k++) {
    if (aux2.vez > (p + k)->vez) {
      for (j = k; j < n; j++) {
        aux = *(p + j);
        *(p + j) = aux2;
        aux2 = aux;
      }
      break;
    } else {
      if (aux2.vez == (p + k)->vez) {
        if (strcmp(aux2.palavra, (p + k)->palavra) < 0) {
          aux = *(p + k);
          *(p + k) = aux2;
          aux2 = aux;
        }
      }
    }
  }
}
void printa(Tno *r) {
  if (r) {
    if (r->esq)
      printa(r->esq);
    printaItem(r->i);
    if (r->dir)
      printa(r->dir);
  }
}
void freeEveryOne(Tno **raiz, int tudo) {
  if (*raiz == NULL) return;
  freeEveryOne(&((*raiz)->esq), tudo);
  freeEveryOne(&((*raiz)->dir), tudo);
  if(tudo){
    free((*raiz)->i);
   free(*raiz);
   }
}


// Usado quando opcao S esta ativa, escontra palavra e printa ela
void achaItem(Tno *raiz, char *word){
  int i;
  if(raiz != NULL){
    i = compara(&(raiz->i), word);
    if(i == 0){
      printaItemPlus((raiz->i), raiz->altura);
      return;
    }
    if(i < 0) {
      achaItem(raiz->dir, word);
      return;
    }
    achaItem(raiz->esq, word);
  }
  else {
    printf("Nao encontrado\n");
  }
}

//para quando a opcao P esta ativa
void printaArvore(Tno *raiz, int max, int maxi){
  //
}


//para quando a opcao B esta ativa
long int vetorizaArvore(Tno *raiz, Tl **lista){
  long int dir, esq;
  if(raiz != NULL){
    esq = vetorizaArvore(raiz->esq, lista);
    insereVetor(lista, raiz);
    dir = vetorizaArvore(raiz->dir, lista);
    return esq + dir + 1;
  }
  return 0;
}

Tl* insereVetor(Tl **lista, Tno *raiz){
  if(*lista == NULL){
    *lista = (Tl*)malloc(sizeof(Tl));
    (*lista)->i = raiz->i;
    (*lista)->prox = NULL;
    return *lista;
  }
  (*lista) -> prox = insereVetor(&((*lista)->prox), raiz);
  return (*lista)->prox;
}

void criaArvoreBalanceada(Tno **raiz, Tl *lista, long int tam, long int altura){
  int i;
  Tl *aux; 
  aux = lista;
  *raiz = (Tno*)malloc(sizeof(Tno));
  (*raiz) -> dir = NULL;
  (*raiz) -> esq = NULL;

  if(tam > 1){
    for(i = 0; i < tam/2; i++){
        aux = aux->prox;
    }

    (*raiz)->i = aux->i;
    (*raiz)->altura = altura;

    if(tam % 2 == 0) criaArvoreBalanceada(&(*raiz)->esq, lista, tam/2, altura + 1);
    else criaArvoreBalanceada(&(*raiz)->esq, lista, (tam - 1)/2, altura + 1);

    criaArvoreBalanceada(&(*raiz)->dir, aux->prox, (tam-1)/2, altura + 1);
    
  }
  else{
     (*raiz)->i = aux->i;
    (*raiz)->altura = altura;
  }
}
void freeVetor(Tl **lista){
  if(*lista == NULL) return;
  freeVetor(&(*lista)->prox);
  free(*lista);
}


