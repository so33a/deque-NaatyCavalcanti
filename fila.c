#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

link novoNo(int item, link prox, link prev) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->prox = prox;
  t->prev = prev;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisDireita = f->maisEsquerda = NULL;
  return f;
}

void inserirmaisEsquerda(FILA f, int e) {
  link novo = malloc(sizeof *novo);
    novo->item = e;
    novo->prev = NULL;
  if(f->maisDireita != NULL){
        f->maisDireita->prev = novo;
        novo->prox = f->maisEsquerda;
    }else{
        f->maisDireita = novo;
        novo->prox=NULL;
    }
    f->maisEsquerda = novo;
}
void inserirmaisDireita(FILA f, int e) {
    link novo = malloc(sizeof *novo);
    novo->item = e;
    novo->prox = NULL;
    if(f->maisDireita != NULL){
        f->maisDireita->prox= novo;
        novo->prev = f->maisDireita;
    }else{
        f->maisEsquerda = novo;
        novo->prev = NULL;
    }
    f->maisDireita = novo;
}

int removermaisEsquerda(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisEsquerda->item;
  t = f->maisEsquerda;
  f->maisEsquerda = f->maisEsquerda->prox;
 
  if(f->maisEsquerda == NULL)
    f->maisDireita = NULL;

  free(t);
  return x;
}
int removermaisDireita(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisDireita->item;
  t = f->maisDireita;
  f->maisDireita = f->maisDireita->prev;
 
  if(f->maisDireita == NULL)
    f->maisEsquerda = NULL;

  free(t);
  return x;
}

int filaVazia(FILA f) {
  return ((f->maisDireita == NULL) || (f->maisEsquerda == NULL));
}
void imprimirmaisEsquerda(FILA f) {
  link t;
  for(t = f->maisEsquerda; t != NULL; t = t->prox) 
    printf ("%d ", t->item);
  printf ("\n");
}

void imprimirmaisDireita(FILA f) {
  link t;
  for(t = f->maisDireita; t != NULL; t = t->prev) 
    printf ("%d ", t->item);
  printf ("\n");
}

void destroiFila(FILA f) {
  while (!filaVazia(f))
    removermaisDireita(f);
  free(f);
}
