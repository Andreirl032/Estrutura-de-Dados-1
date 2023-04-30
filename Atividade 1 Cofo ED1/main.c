// FEITO POR ANDREI RAMOS LOPES
// replit: https://replit.com/@Andrei032/atividade-1-implementacao-ed1-cofo#
#include "cofo.h"
#include <stdio.h>

int main(void) {
  Cofo *meuCofo = cofCreate(5);
  cofInsert(meuCofo, 5);
  cofInsert(meuCofo, 8);
  printf("%d\n", cofQuery(meuCofo, 7));
  printf("%d\n", cofQuery(meuCofo, 5));
  cofRemove(meuCofo, 5);
  printf("%d\n", cofQuery(meuCofo, 5));
  cofDestroy(meuCofo);
  return 0;
}