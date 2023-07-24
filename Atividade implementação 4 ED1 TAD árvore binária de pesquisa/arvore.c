// FEITO POR ANDREI RAMOS LOPES
#include "arvore.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

TNode *abpCreate() {
  TNode *t = (TNode *)malloc(sizeof(TNode));
  t->data = NULL;
  t->l = NULL;
  t->r = NULL;
  return t;
}

int abpDestroy(TNode *t) {
  if (t != NULL) {
    if (t->l == NULL && t->r == NULL && t->data == NULL) {
      free(t);
      return true;
    }
  }
  return false;
}

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *)) {
  int stat;
  if (t != NULL) {
    stat = cmp(key, t->data);
    if (stat == 0) {
      return t->data;
    } else if (stat < 0) {
      return abpQuery(t->l, key, cmp);
    } else {
      return abpQuery(t->r, key, cmp);
    }
  }
  return NULL;
}

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *)) {
  TNode *newnode;
  if (t != NULL) {
    // if(t->data==NULL && t->l==NULL && t->r==NULL){
    //   t->data=data;
    //   return t;
    // }
    
    if (cmp(data, t->data) <= 0) {
      t->l = abpInsert(t->l, data, cmp);
      return t;
    } else {
      t->r = abpInsert(t->r, data, cmp);
      return t;
    }
  }
  newnode = (TNode *)malloc(sizeof(TNode));
  if (newnode != NULL) {
    newnode->data = data;
    newnode->l = NULL;
    newnode->r = NULL;
    return newnode;
  }
  return NULL;
}

TNode *minValueNode(TNode *abp) {
  TNode *current = abp;
  if (current == NULL) {
    return NULL;
  }
  while (current && current->l != NULL)
    current = current->l;
  return current;
}
TNode *maxValueNode(TNode *abp) {
  TNode *current = (TNode *)malloc(sizeof(TNode));
  current = abp;
  if (current == NULL || abp == NULL) {
    return NULL;
  }
  while (current && current->r != NULL) {
    current = current->r;
  }
  return current;
}


void visitInt(void *num) { 
  printf("%d\n", *(int *)num); 
}

void abpListAll(TNode *t, void (visit)(void *)) {
  if (t != NULL) {
    abpListAll(t->l, visit);
    if(t->data!=NULL){
    visit(t->data);
    }
    abpListAll(t->r, visit);
  }
}

TNode* abpRemove(TNode* t, void* key, int (*cmp)(void*, void*)) {
    if (t == NULL){
        return t;
    }
    if (cmp(key, t->data) < 0){
        t->l = abpRemove(t->l, key, cmp);
    } else if (cmp(key, t->data) > 0){
        t->r = abpRemove(t->r, key, cmp);
    } else {
        if(t->l==NULL && t->r==NULL){
          free(t);
          return NULL;
        }
        if (t->l == NULL) {
            TNode* temp = t->r;
            free(t);
            return temp;
        } else if (t->r == NULL) {
            TNode* temp = t->l;
            free(t);
            return temp;
        } else{
        TNode* temp = minValueNode(t->r);
        
        t->data = temp->data;
      
        t->r = abpRemove(t->r, temp->data, cmp);
        }
    }
    return t;
}

// void abpClear(TNode *t,int (*cmp)(void *,void *)) {
//   if (t != NULL) {
//     abpClear(t->l,cmp);
//     abpClear(t->r,cmp);
//     abpRemove(t,t->data,cmp);
//   }
// }