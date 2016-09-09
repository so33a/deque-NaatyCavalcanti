#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisDireita = f->maisEsquerda = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->maisEsquerda == NULL) {
    f->maisEsquerda = f->maisDireita = novoNo(e, NULL);
  } else {
    f->maisDireita->next = novoNo(e, NULL);
    f->maisDireita = f->maisDireita->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;
 
  if(f->maisEsquerda == NULL)
    f->maisDireita = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->maisDireita == NULL) || (f->maisEsquerda == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->maisEsquerda; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

