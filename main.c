#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserirmaisEsquerda(alunos, 9);
  inserirmaisDireita(alunos, 8);
  inserirmaisEsquerda(alunos, 3);
  inserirmaisDireita(alunos, 10);

  imprimirmaisEsquerda(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removermaisDireita(alunos));

  inserirmaisDireita(alunos, 10);
  inserirmaisEsquerda(alunos, 32);
  
  imprimirmaisDireita(alunos);

  destroiFila(alunos);
  return 0;
}
