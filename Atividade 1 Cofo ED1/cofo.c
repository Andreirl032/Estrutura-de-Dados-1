// FEITO POR ANDREI RAMOS LOPES
#include "cofo.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _COFO_C_
#define _COFO_C_

Cofo *cofCreate(int maxItens) {
  Cofo *c;
  Cofo var_c;
  if (maxItens > 0) {
    c = (Cofo *)malloc(sizeof(Cofo));
    if (c != NULL) {
      c->item = (int *)malloc(sizeof(int) * maxItens);
      if (c->item != NULL) {
        c->numItens = 0;
        c->maxItens = maxItens;
        return c;
      }
      free(c);
    }
  }
  return NULL;
}

int cofDestroy(Cofo *c) {
  if (c != NULL) {
    if (c->numItens == 0) {
      free(c->item);
      free(c);
      return 1;
    }
  }
  return 0;
}

int cofInsert(Cofo *c, int item) {
  if (c != NULL) {
    if (c->numItens < c->maxItens) {
      c->item[c->numItens] = item;
      c->numItens++;
      return 1;
    }
  }
  return 0;
}

int cofQuery(Cofo *c, int key) {
  int i, status;
  if (c != NULL) {
    if (c->numItens > 0) {
      i = 0;
      status = 0;
      while (i < c->numItens && status != 1) {
        if (c->item[i] == key) {
          status = 1;
        } else {
          i++;
        }
      }
      if (status == 1) {
        return 1;
      }
    }
  }
  return 0;
}

int cofRemove(Cofo *c, int key) {
  int i, j, status, aux;
  if (c != NULL) {
    if (c->numItens > 0) {
      i = 0;
      status = 0;
      while (i<c->numItens> 0 && status != 1) {
        if (c->item[i] == key) {
          status = 1;
        } else {
          i++;
        }
      }
      if (status == 1) {
        aux = c->item[i];
        for (j = i; j < c->numItens - 1; j++) {
          c->item[j] = c->item[j + 1];
        }
        return aux;
      }
    }
  }
  return -32777;
}

#endif