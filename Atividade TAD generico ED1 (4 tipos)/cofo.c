#include "cofo.h"
#include <stdio.h>
#include <stdlib.h>

gCofo *gcofCreate(int max_itens) {
  gCofo *gc;
  if (max_itens > 0) {
    gc = (gCofo *)malloc(sizeof(gCofo));
    if (gc != NULL) {
      gc->item = (void **)malloc(sizeof(void *) * max_itens);
      if (gc->item != NULL) {
        gc->numItens = 0;
        gc->maxItens = max_itens;
        gc->atual = -1;
        return gc;
      }
      free(gc);
    }
  }
  return NULL;
}

int gcofDestroy(gCofo *gc) {
  if (gc != NULL) {
    if (gc->numItens == 0) {
      free(gc->item);
      free(gc);
      return 1;
    }
  }
  return 0;
}

int gcofInsert(gCofo *gc, void *item) {
  if (gc != NULL) {
    if (gc->numItens < gc->maxItens) {
      gc->item[gc->numItens] = item;
      gc->numItens++;
      return 1;
    }
  }
  return 0;
}

/*void *gcofGetFirst(gCofo *gc) {
  void *elm;
  if (gc != NULL) {
    if (gc->numItens > 0) {
      elm = gc->item[0];
      gc->atual = 0;
      return elm;
    }
  }
  return NULL;
}

void *gcofGetNext(gCofo *gc) {
  void *elm;
  if (gc != NULL) {
    if (gc->numItens > 0 && gc->atual < gc->numItens - 1) {
      gc->atual++;
      elm = gc->item[gc->atual];
      return elm;
    }
  }
  return NULL;
}*/

void *gcofAll(gCofo *gc){
  
}

void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *, void *)) {
  int i;
  int data;
  int stat;
  if (gc != NULL) {
    if (gc->numItens > 0) {
      i = 0;
      stat = cmp(gc->item[i], key);
      while (i < gc->numItens && stat != 1 && gc->numItens>1) {
        i++;
        stat = cmp(gc->item[i], key);
      }
      if (stat == 1) {
        return gc->item[i];
      }
    }
  }
  return NULL;
}

void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *, void *)) {
  int i;
  void *data;
  int stat;
  if (gc != NULL) {
    if (gc->numItens > 0) {
      i = 0;
      stat = cmp(key, gc->item[i]);
      while (i < gc->numItens && stat != 1) {
        i++;
        stat = cmp(key, gc->item[i]);
      }
      if (stat == 1) {
        data = gc->item[i];
        for (int j = i; j < gc->numItens; j++) {
          gc->item[j] = gc->item[j + 1];
        }
        gc->numItens--;
        return data;
      }
    }
  }
  return NULL;
}