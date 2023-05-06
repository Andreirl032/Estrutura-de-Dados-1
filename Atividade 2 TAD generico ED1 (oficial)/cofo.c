//FEITO POR ANDREI RAMOS LOPES
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

int gcofAll(gCofo *gc){
  int i;
  if(gc!=NULL){
  Aluno *aluno=(Aluno *)malloc(sizeof(Aluno));
    if(gc->numItens>0 && aluno!=NULL){
      i=0;
      while(i<gc->numItens){
        aluno=gc->item[i];
        printf("\nElemento número %d:\n",i+1);
        printf("- Matrícula: %d\n",aluno->matricula);
        printf("- Nome completo: %s\n",aluno->nome_completo);
        printf("- CR: %f\n\n",aluno->cr);
        i++;
      }
      return 1;
    }
  }
  return 0;
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