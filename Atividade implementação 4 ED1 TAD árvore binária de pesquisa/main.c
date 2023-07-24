// FEITO POR ANDREI RAMOS LOPES
// https://replit.com/@Andrei032/atividade-4-implementacao-ed1-tad-abp#main.c
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpInt(void *a, void *b) {
  int *ptrA, *ptrB;
  ptrA = (int *)a;
  ptrB = (int *)b;
  if (ptrA == NULL || ptrB == NULL) {
    return -32767;
  }
  if (*ptrA > *ptrB) {
    return 1;
  } else if (*ptrA < *ptrB) {
    return -1;
  } else {
    return 0;
  }
}

void format(char *frase, int num) {
  int rowlen = 60;
  int fraselen = strlen(frase) - 1;
  int num_lados = (rowlen - fraselen) / 2;
  if ((!(strcmp(frase, "-"))) == 1) {
    for (int i = 0; i < num; i++) {
      printf(
          "------------------------------------------------------------\n\n");
    }
  } else {
    if (fraselen % 2 == 0) {
      for (int i = 0; i < num; i++) {
        for (int i = 0; i < num_lados; i++) {
          printf("-");
        }
        printf("%s", frase);
        for (int i = 0; i < num_lados; i++) {
          printf("-");
        }
        printf("\n\n");
      }
    } else {
      for (int i = 0; i < num; i++) {
        for (int i = 0; i < num_lados; i++) {
          printf("-");
        }
        printf("%s", frase);
        for (int i = -1; i < num_lados; i++) {
          printf("-");
        }
        printf("\n\n");
      }
    }
  }
}

void redFormat(char *text, int number) {
  printf("\x1b[31m");
  format(text, number);
  printf("\x1b[m");
}

TNode *formatCreateAbp() {
  int *inteiro=(int *)malloc(sizeof(int));
  format("-", 1);
  format("CRIAÇÃO DE ÁRVORE", 1);
  format("-", 1);
  // printf("Insira o primeiro elemento da árvore:\n");
  // scanf("%d", inteiro);
  // getchar();
  
  TNode *arvore = abpCreate();
  if (arvore != NULL) {
    printf("A ÁRVORE DE PESQUISA FOI CRIADA COM SUCESSO\n");
  } else {
    printf("ERRO\n");
  }
  return arvore;
}

int formatDestroyAbp(TNode *abp) {
  char destruir;
  format("-", 1);
  format("DESTRUIÇÃO DE ÁRVORE", 1);
  printf("Tem certeza de que quer destruir(serrar kk) a árvore?: (S/N)\n");
  scanf("%c", &destruir);
  getchar();
  if (destruir == 's' || destruir == 'S') {
    int destroy = abpDestroy(abp);
    if (destroy == 1) {
      printf("A ÁRVORE FOI DESTRUÍDA COM SUCESSO\n");
    } else {
      printf("ERRO\n");
    }
    return destroy;
  } else if (destruir == 'n' || destruir == 'N') {
    return 0;
  } else {
    printf("INSIRA UM VALOR VÁLIDO\n");
    return 0;
  }
}

TNode *formatInsertAbp(TNode *abp, int (*cmp)(void *, void *)) {
  format("-", 1);
  format("INSERIR NA ÁRVORE", 1);
  format("-", 1);
  printf("Insira um inteiro para adicionar à árvore:\n");
  int *inteiro = (int *)malloc(sizeof(int));
  scanf("%d", inteiro);
  getchar();
  if (inteiro == NULL) {
    return 0;
  }

  if(abp->data==NULL){
    abp->data=(void *)inteiro;
    return abp;
  }
  
  TNode *insert = abpInsert(abp, (void *)inteiro, cmp);
  if (insert != NULL) {
    printf("O ELEMENTO FOI INSERIDO NA ÁRVORE COM SUCESSO\n");
  } else {
    printf("ERRO\n");
    return NULL;
  }
  return insert;
}

void *formatQueryAbp(TNode *abp, int (*cmp)(void *, void *)) {
  format("-", 1);
  format("PROCURAR NA ÁRVORE", 1);
  format("-", 1);
  printf("Insira um inteiro para procurar na árvore:\n");
  int *inteiro = (int *)malloc(sizeof(int));
  scanf("%d", inteiro);
  getchar();

  if (inteiro == NULL) {
    printf("ERRO\n");
    return NULL;
  }
  
  void *ptrQueryAbp = abpQuery(abp, (void *)inteiro, cmp);
  if (ptrQueryAbp == NULL) {
    printf("Ocorreu um erro ou o elemento não está na árvore\n");
    return NULL;
  }
  printf("O elemento está presente na árvore\n");
  return ptrQueryAbp;
}

void formatListAllAbp(TNode *abp, void (visit)(void *)){
  format("-", 1);
  format("LISTA DE ELEMENTOS DA ÁRVORE:", 1);
  format("-", 1);
  if(abp->data!=NULL && abp->l==NULL && abp->r==NULL){
    printf("%d\n",*(int *)abp->data);
  } else{
  abpListAll(abp, visit);
  }
  printf("\n\n");
}

TNode *formatRemoveAbp(TNode *abp,int (*cmp)(void *,void *)) {
  format("-", 1);
  format("REMOVER DA ÁRVORE", 1);
  format("-", 1);
  printf("Insira um inteiro para remover da árvore:\n");
  int *inteiro = (int *)malloc(sizeof(int));
  scanf("%d", inteiro);
  getchar();
  if (inteiro == NULL) {
    printf("ERRO\n");
    return NULL;
  }
  // void *ptrRemoveAbp = abpRemove(abp, (void *)inteiro, cmp,data);
  // printf("oi %d\n",**(int **)data);
  if(abp->data!=NULL && (abp->l==NULL || abp->r==NULL)){
    abp->data=NULL;
    return abp;
  }
  TNode *ptrRemoveAbp = abpRemove(abp, (void *)inteiro,cmp);
  printf("oi %d\n",*(int *)ptrRemoveAbp->data);
  if (ptrRemoveAbp == NULL) {
    printf("Ocorreu um erro ou o elemento não está na árvore\n");
    return NULL;
  }
    printf("O aluno foi removido da árvore\n");
    return ptrRemoveAbp;
}

// int formatClearAbp(TNode *abp,int (*cmp)(void *,void *)) {
//   char clear;
//   format("-", 1);
//   format("LIMPEZA DE ÁRVORE", 1);
//   printf("Tem certeza de que quer esvaziar a árvore?: (S/N)\n");
//   scanf("%c", &clear);
//   getchar();
//   if (clear == 's' || clear == 'S') {
//     abpClear(abp,cmp);
//     return 1;
//   } else if (clear == 'n' || clear == 'N') {
//     return 0;
//   } else {
//     printf("INSIRA UM VALOR VÁLIDO\n");
//     return 0;
//   }
// }

void caseFunction() {
  int number;
  int thereIsAbp = 0;
  TNode *arvore = NULL;
  while (1) {
    printf("Pressione:\n\n");
    if (thereIsAbp == 0) {
      format("[1] - Criar árvore binária de pesquisa", 1);
    } else {
      redFormat("[1] - Criar árvore binária de pesquisa", 1);
    }
    if (thereIsAbp == 1 && arvore->l == NULL && arvore->r==NULL && arvore->data==NULL) {
      format("[2] - Destruir árvore binária de pesquisa", 1);
    } else {
      redFormat("[2] - Destruir árvore binária de pesquisa", 1);
    }
    if (thereIsAbp == 1) {
      format("[3] - Inserir item na árvore binária de pesquisa", 1);
    } else {
      redFormat("[3] - Inserir item na árvore binária de pesquisa", 1);
    }
    if (thereIsAbp == 1 && (arvore->data!=NULL || arvore->l!=NULL || arvore->r!=NULL)) {
      format("[4] - Listar os elementos da árvore binária de pesquisa", 1);
      format("[5] - Consultar elemento da árvore binária de pesquisa", 1);
      format("[6] - Remover elemento da árvore binária de pesquisa", 1);
      // format("[7] - Esvaziar a árvore binária de pesquisa", 1);
    } else {
      redFormat("[4] - Listar os elementos do árvore binária de pesquisa", 1);
      redFormat("[5] - Consultar elemento da árvore binária de pesquisa", 1);
      redFormat("[6] - Remover elemento da árvore binária de pesquisa", 1);
    //   redFormat("[7] - Esvaziar a árvore binária de pesquisa", 1);
    }
    format("[7] - Finalizar programa", 1);

    scanf("%d", &number);
    getchar();

    switch (number) {
    case 1:
      if (thereIsAbp == 0) {
        arvore = formatCreateAbp();
        if (arvore != NULL) {
          thereIsAbp = 1;
        }
      } else{
        printf("Já há uma árvore presente. Delete-a para criar outra.\n");
      }
      break;

    case 2:
      if (thereIsAbp == 1 && arvore != NULL) {
        if (arvore->l == NULL && arvore->r==NULL && arvore->data==NULL) {
          if (formatDestroyAbp(arvore) == 1) {
            thereIsAbp = 0;
          }
        } else {
          printf("ÁRVORE PRECISA ESTAR VAZIA PARA SER DESTRUÍDA\n");
        }
      }
      break;

    case 3:
      if (thereIsAbp == 1) {
        formatInsertAbp(arvore,cmpInt);
      } else{
        printf("Crie uma árvore antes de prosseguir\n");
      }
      break;

      case 4:
        if (thereIsAbp == 1) {
          if (arvore->data!=NULL || arvore->l!=NULL || arvore->r!=NULL) {
            formatListAllAbp(arvore,visitInt);
          } else {
            printf("A ÁRVORE NÃO POSSUI ELEMENTOS\n");
          }
        } else{
          printf("Crie uma árvore antes de prosseguir\n");
        }
        break;

    case 5:
      if (thereIsAbp == 1) {
        if (arvore->data!=NULL || arvore->l!=NULL || arvore->r!=NULL) {
          formatQueryAbp(arvore, cmpInt);
        } else {
          printf("A ÁRVORE NÃO POSSUI ELEMENTOS\n");
        }
      } else{
          printf("Crie uma árvore antes de prosseguir\n");
        }
      break;

      case 6:
        if (thereIsAbp == 1) {
          if (arvore->data!=NULL || arvore->l!=NULL || arvore->r!=NULL) {
            formatRemoveAbp(arvore,cmpInt);
          } else {
            printf("A ÁRVORE NÃO POSSUI ELEMENTOS\n");
          }
        } else{
          printf("Crie uma árvore antes de prosseguir\n");
        }
        break;

      // case 7:
      //   if (thereIsAbp == 1) {
      //     if (arvore->l!=NULL || arvore->r!=NULL) {
      //       formatClearAbp(arvore,cmpInt);
      //     } else {
      //       printf("A ÁRVORE NÃO POSSUI ELEMENTOS\n");
      //     }
      //   }
      //   break;

    case 7:
      printf("Obrigado e volte sempre!");
      return;

    default:
      printf("INSIRA UM VALOR VÁLIDO!\n");
      break;
    }
  }
}

int main(void) {
  format("-", 3);
  format("TAD ÁRVORE BINÁRIA DE PESQUISA", 1);
  format("-", 3);
  caseFunction();
  // int val1 = 10;
  // int val2 = 20;
  // int val3 = 7;

  // TNode *arvore = abpCreate(&val1);

  // arvore = abpInsert(arvore, &val2, cmpInt);
  // arvore = abpInsert(arvore, &val3, cmpInt);

  // abpListAll(arvore, visitInt);
  
  // abpDestroy(arvore);
  
  return 0;
}