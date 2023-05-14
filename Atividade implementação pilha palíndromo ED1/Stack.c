#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *stkCreate(int max) {
  Stack *s;
  if (max > 0) {
    s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL) {
      s->item = (void **)malloc(sizeof(void *) * max);
      if (s->item != NULL) {
        s->maxItens = max;
        s->top = -1;
        return s;
      }
    }
  }
  return NULL;
}

int stkDestroy(Stack *s) {
  if (s != NULL) {
    if (s->top < 0) {
      free(s->item);
      free(s);
      return 0;
    }
  }
  return 1;
}

int stkPush(Stack *s, void *elm) {
  if (s != NULL) {
    if (s->top < s->maxItens - 1) {
      s->top++;
      s->item[s->top] = elm;
      return 0;
    }
  }
  return 1;
}

void *stkPop(Stack *s) {
  void *aux;
  if (s != NULL) {
    if (s->top >= 0) {
      aux = s->item[s->top];
      s->top--;
      return aux;
    }
  }
  return NULL;
}

void *stkTop(Stack *s) {
  void *aux;
  if (s != NULL) {
    if (s->top >= 0) {
      aux = s->item[s->top];
      return aux;
    }
  }
  return NULL;
}

int stkIsEmpty(Stack *s) {
  if (s != NULL) {
    if (s->top < 0) {
      return 0;
    }
  }
  return 1;
}

int Epalindromo(char *s, int n) {
  if (s != NULL) {
    Stack *pilha = stkCreate(n);
    for (int i = 0; i < n; i++) {
      stkPush(pilha, (void *)&s[i]);
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != *((char *)stkPop(pilha))) {
        printf("NÃO É PALÍNDROMO");
        stkDestroy(pilha);
        return 1;
      }
    }
    printf("É PALÍNDROMO");
    stkDestroy(pilha);
    return 0;
  }
}