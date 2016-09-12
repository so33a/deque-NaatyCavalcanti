#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
  link prev;
};

typedef struct {
  link maisEsquerda;
  link maisDireita;
} * FILA;

link novoNo(int item, link next, link prev);
FILA novaFila();
void inserirmaisEsquerda(FILA f, int e);
void inserirmaisDireita(FILA f, int e);
int removermaisEsquerda(FILA f);
int removermaisDireita(FILA f);
void imprimirmaisEsquerda(FILA f);
void imprimirmaisDireita(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 
