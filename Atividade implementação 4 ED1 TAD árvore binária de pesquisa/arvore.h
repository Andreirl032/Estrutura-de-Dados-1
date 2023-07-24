// FEITO POR ANDREI RAMOS LOPES
#ifndef _ARVORE_H_
#define _ARVORE_H_
#ifdef _ARVORE_C_

typedef struct _tnode_ {
  void *data;
  struct _tnode_ *l;
  struct _tnode_ *r;
} TNode;

TNode *abpCreate();
int abpDestroy(TNode *t);
void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *));
TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *));
TNode *minValueNode(TNode *abp);
TNode *maxValueNode(TNode *abp);
// TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data);
TNode *abpRemove(TNode* t, void* key, int (*cmp)(void*, void*));
void visitInt(void *num);
void abpListAll(TNode *t, void (*visit)(void *));

// typedef struct _aluno_ {
//   int matricula;
//   char nome_completo[30];
//   float cr;
// } Aluno;
// typedef struct _gcofo_ {
//   int numItens;
//   int maxItens;
//   int atual;
//   void **item;
// } gCofo;
// gCofo *gcofCreate(int max_itens);
// int gcofInsert(gCofo *c, void *item);
// void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *));
// void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *));
// int gcofAll(gCofo *c);
// int gcofClear(gCofo *c, int (*cmp)(void *, void *));
// int gcofDestroy(gCofo *c);

#else
typedef struct _tnode_ {
  void *data;
  struct _tnode_ *l;
  struct _tnode_ *r;
} TNode;

extern TNode *abpCreate();
extern int abpDestroy(TNode *t);
extern void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *));
extern TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *));
extern TNode *minValueNode(TNode *abp);
extern TNode *maxValueNode(TNode *abp);
// extern TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *),void **data);
extern TNode *abpRemove(TNode* t, void* key, int (*cmp)(void*, void*));
extern void visitInt(void *num);
extern void abpListAll(TNode *t, void (*visit)(void *));

// typedef struct _gcofo_ {
//   int numItens;
//   int maxItens;
//   int atual;
//   void **item;
// } gCofo;
// typedef struct _aluno_ {
//   int matricula;
//   char nome_completo[30];
//   float cr;
// } Aluno;
// extern gCofo *gcofCreate(int max_itens);
// extern int gcofInsert(gCofo *c, void *item);
// extern void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *));
// extern void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void *));
// int gcofAll(gCofo *c);
// extern int gcofDestroy(gCofo *c);
// extern int gcofClear(gCofo *c, int (*cmp)(void *, void *));
#endif
#endif