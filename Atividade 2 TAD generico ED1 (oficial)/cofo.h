// FEITO POR ANDREI RAMOS LOPES
#ifndef _GCOFO_H_
#define _GCOFO_H_
#ifdef _GCOFO_C_

typedef struct _aluno_ {
  int matricula;
  char nome_completo[30];
  float cr;
} Aluno;
typedef struct _gcofo_ {
  int numItens;
  int maxItens;
  int atual;
  void **item;
} gCofo;
gCofo *gcofCreate(int max_itens);
int gcofInsert(gCofo *c, void *item);
void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *));
void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *));
int gcofAll(gCofo *c);
int gcofClear(gCofo *c, int (*cmp)(void *, void *));
int colDestroy(gCofo *c);

#else
typedef struct _gcofo_ {
  int numItens;
  int maxItens;
  int atual;
  void **item;
} gCofo;
typedef struct _aluno_ {
  int matricula;
  char nome_completo[30];
  float cr;
} Aluno;
extern gCofo *gcofCreate(int max_itens);
extern int gcofInsert(gCofo *c, void *item);
extern void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *));
extern void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *));
int gcofAll(gCofo *c);
extern int colDestroy(gCofo *c);
extern int gcofClear(gCofo *c, int (*cmp)(void *, void *));
#endif
#endif