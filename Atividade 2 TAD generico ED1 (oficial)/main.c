// FEITO POR ANDREI RAMOS LOPES
// https://replit.com/@Andrei032/atividade-2-implementacao-ed1-tad-generico#main.c
#include "cofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpAluno(void *a, void *b) {
  Aluno *ptrA, *ptrB;
  ptrA = (Aluno *)a;
  ptrB = (Aluno *)b;
  if (ptrA == NULL || ptrB == NULL) {
    return 0;
  }
  if (ptrA->matricula == ptrB->matricula) {
    if (!(strcmp(ptrA->nome_completo, ptrB->nome_completo)) == 1) {
      if (ptrA->cr == ptrB->cr) {
        return 1;
      }
    }
  }
  return 0;
}

void format(char *frase, int num) {
  int rowlen = 60;
  int fraselen = strlen(frase) - 1;
  int num_lados = (rowlen - fraselen) / 2;
  if (!(strcmp(frase, "-")) == 1) {
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

void *formatCreateCofo() {
  int max;
  format("-", 1);
  format("CRIAÇÃO DE COFO", 1);
  printf("Insira o número máximo de elementos do cofo:\n");
  scanf("%d", &max);
  getchar();

  gCofo *cofo = gcofCreate(max);
  if(cofo!=NULL){
    printf("O COFO FOI CRIADO COM SUCESSO\n");
  } else{
    printf("ERRO\n");
  }
  return cofo;
}

int formatDestroyCofo(gCofo *cofo) {
  char destruir;
  format("-", 1);
  format("DESTRUIÇÃO DE COFO", 1);
  printf("Tem certeza de que quer destruir o cofo?: (S/N)\n");
  scanf("%c", &destruir);
  getchar();
  if (destruir == 's' || destruir == 'S') {
    int destroy=gcofDestroy(cofo);
    if(destroy==1){
    printf("O COFO FOI DESTRUÍDO COM SUCESSO\n");
  } else{
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

int formatInsertCofo(gCofo *cofo) {
  format("-", 1);
  format("INSERIR NO COFO", 1);
  format("-", 1);
  printf("Insira uma matrícula para adicionar ao cofo:\n");
  Aluno *aluno = (Aluno *)malloc(sizeof(aluno));

  int *matricula = (int *)malloc(sizeof(int));
  scanf("%d", matricula);
  getchar();
  printf("Insira o nome completo do aluno para adicionar ao cofo:\n");
  scanf("%[^\n]", aluno->nome_completo);
  getchar();
  printf("Insira um coeficiente de rendimento para adicionar ao cofo:\n");
  float *cr = (float *)malloc(sizeof(float));
  scanf("%f", cr);
  getchar();

  aluno->matricula = *matricula;
  aluno->cr = *cr;
  if (aluno == NULL || matricula == NULL || cr == NULL) {
    return 0;
  }
  int insert=gcofInsert(cofo, (void *)aluno);
  if(insert==1){
    printf("O ELEMENTO FOI INSERIDO NO COFO COM SUCESSO");
  } else{
    printf("ERRO");
  }
  return insert;
}

int formatQueryCofo(gCofo *cofo) {
  format("-", 1);
  format("PROCURAR NO COFO", 1);
  format("-", 1);
  printf("Insira uma matrícula para adicionar ao cofo:\n");
  Aluno *aluno = (Aluno *)malloc(sizeof(aluno));

  int *matricula = (int *)malloc(sizeof(int));
  scanf("%d", matricula);
  getchar();
  printf("Insira o nome completo do aluno para adicionar ao cofo:\n");
  scanf("%[^\n]", aluno->nome_completo);
  getchar();
  printf("Insira um coeficiente de rendimento para adicionar ao cofo:\n");
  float *cr = (float *)malloc(sizeof(float));
  scanf("%f", cr);
  getchar();

  aluno->matricula = *matricula;
  aluno->cr = *cr;

  if (aluno == NULL) {
    printf("ERRO\n");
    return 0;
  }
  void *ptrAluno = (void *)aluno;
  void *cofoQueryAluno = gcofQuery(cofo, ptrAluno, cmpAluno);
  if (cofoQueryAluno == NULL) {
    printf("Ocorreu um erro ou o aluno não está no cofo\n");
    return 0;
  }
  Aluno *queryAluno = (Aluno *)cofoQueryAluno;
  if (queryAluno->matricula == aluno->matricula &&
      queryAluno->cr == aluno->cr &&
      !(strcmp(queryAluno->nome_completo, aluno->nome_completo)) == 1) {
    printf("O aluno está presente no cofo\n");
    return 1;
  } else {
    printf("O aluno NÃO está presente no cofo\n");
    return 0;
  }
  return 0;
}

int formatRemoveCofo(gCofo *cofo) {
  format("-", 1);
  format("REMOVER DO COFO", 1);
  format("-", 1);
  printf("Insira uma matrícula para remover do cofo:\n");
  Aluno *aluno = (Aluno *)malloc(sizeof(aluno));

  int *matricula = (int *)malloc(sizeof(int));
  scanf("%d", matricula);
  getchar();
  printf("Insira o nome completo do aluno para remover do cofo:\n");
  scanf("%[^\n]", aluno->nome_completo);
  getchar();
  printf("Insira um coeficiente de rendimento para remover do cofo:\n");
  float *cr = (float *)malloc(sizeof(float));
  scanf("%f", cr);
  getchar();

  aluno->matricula = *matricula;
  aluno->cr = *cr;

  if (aluno == NULL) {
    printf("ERRO\n");
    return 0;
  }
  void *ptrAluno = (void *)aluno;
  void *cofoRemoveAluno = gcofRemove(cofo, ptrAluno, cmpAluno);
  if (cofoRemoveAluno == NULL) {
    printf("Ocorreu um erro ou o aluno não está no cofo\n");
    return 0;
  }
  Aluno *removeAluno = (Aluno *)cofoRemoveAluno;
  if (removeAluno->matricula == aluno->matricula &&
      removeAluno->cr == aluno->cr &&
      !(strcmp(removeAluno->nome_completo, aluno->nome_completo)) == 1) {
    printf("O aluno foi removido do cofo\n");
    return 1;
  } else {
    printf("O aluno NÃO está presente no cofo\n");
    return 0;
  }
  return 0;
}

int formatClearCofo(gCofo *cofo) {
  char clear;
  format("-", 1);
  format("LIMPEZA DE COFO", 1);
  printf("Tem certeza de que quer esvaziar o cofo?: (S/N)\n");
  scanf("%c", &clear);
  getchar();
  if (clear == 's' || clear == 'S') {
    int clear=gcofClear(cofo, cmpAluno);
    if(clear==1){
      printf("O COFO FOI ESVAZIADO COM SUCESSO\n");
    }
    else{
      printf("ERRO\n");
    }
    return clear;
  } else if (clear == 'n' || clear == 'N') {
    return 0;
  } else {
    printf("INSIRA UM VALOR VÁLIDO\n");
    return 0;
  }
}

void caseFunction() {
  int number;
  int thereIsCofo = 0;
  gCofo *cofo = NULL;
  while (1) {
    printf("Pressione:\n\n");
    if (thereIsCofo == 0) {
      format("[1] - Criar cofo genérico", 1);
    } else {
      redFormat("[1] - Criar cofo genérico", 1);
    }
    if (thereIsCofo == 1 && cofo->numItens == 0) {
      format("[2] - Destruir cofo genérico", 1);
    } else {
      redFormat("[2] - Destruir cofo genérico", 1);
    }
    if (thereIsCofo == 1 && cofo->numItens < cofo->maxItens) {
      format("[3] - Inserir item no cofo genérico", 1);
    } else {
      redFormat("[3] - Inserir item no cofo genérico", 1);
    }
    if (thereIsCofo == 1 && cofo->numItens > 0) {
      format("[4] - Listar os elementos do cofo genérico", 1);
      format("[5] - Consultar elemento do cofo genérico", 1);
      format("[6] - Remover elemento do cofo genérico", 1);
      format("[7] - Esvaziar o cofo genérico", 1);
    } else {
      redFormat("[4] - Listar os elementos do cofo genérico", 1);
      redFormat("[5] - Consultar elemento do cofo genérico", 1);
      redFormat("[6] - Remover elemento do cofo genérico", 1);
      redFormat("[7] - Esvaziar o cofo genérico", 1);
    }
    format("[8] - Finalizar programa", 1);

    scanf("%d", &number);
    getchar();

    switch (number) {
    case 1:
      if (thereIsCofo == 0) {
        cofo = formatCreateCofo();
        if (cofo != NULL) {
          thereIsCofo = 1;
        }
      }
      break;

    case 2:
      if (thereIsCofo == 1 && cofo != NULL) {
        if (cofo->numItens == 0) {
          if (formatDestroyCofo(cofo) == 1) {
            thereIsCofo = 0;
          }
        } else {
          printf("O COFO PRECISA ESTAR VAZIO PARA SER DESTRUÍDO\n");
        }
      }
      break;

    case 3:
      if (thereIsCofo == 1) {
        if (cofo->numItens < cofo->maxItens) {
          formatInsertCofo(cofo);
        } else {
          printf("O COFO ESTÁ CHEIO\n");
        }
      }
      break;

    case 4:
      if (thereIsCofo == 1) {
        if (cofo->numItens > 0) {
          gcofAll(cofo);
        } else {
          printf("O COFO NÃO POSSUI ELEMENTOS\n");
        }
      }
      break;

    case 5:
      if (thereIsCofo == 1) {
        if (cofo->numItens > 0) {
          formatQueryCofo(cofo);
        } else {
          printf("O COFO NÃO POSSUI ELEMENTOS\n");
        }
      }
      break;

    case 6:
      if (thereIsCofo == 1) {
        if (cofo->numItens > 0) {
          formatRemoveCofo(cofo);
        } else {
          printf("O COFO NÃO POSSUI ELEMENTOS\n");
        }
      }
      break;

    case 7:
      if (thereIsCofo == 1) {
        if (cofo->numItens > 0) {
          formatClearCofo(cofo);
        } else {
          printf("O COFO NÃO POSSUI ELEMENTOS\n");
        }
      }
      break;

    case 8:
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
  format("TAD GENÉRICO", 1);
  format("-", 3);
  caseFunction();
  return 0;
}