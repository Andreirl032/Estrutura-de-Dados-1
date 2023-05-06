#include "cofo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpAluno(void *a, void *b) {
  Aluno *ptrA, *ptrB;
  ptrA = (Aluno *)a;
  ptrB = (Aluno *)b;
  if (ptrA->matricula == ptrB->matricula) {
    if (!(strcmp(ptrA->nome_completo,ptrB->nome_completo))==1) {
      if (ptrA->cr == ptrB->cr) {
        return 1;
      }
    }
  }
  return 0;
}


int cmpInt(void *a, void *b) {
  int *ptrA, *ptrB;
  ptrA = (int *)a;
  ptrB = (int *)b;
  if (*ptrA == *ptrB) {
    return 1;
  } else {
    return 0;
  }
}

int cmpFloat(void *a, void *b) {
  float *ptrA, *ptrB;
  ptrA = (float *)a;
  ptrB = (float *)b;
  if (*ptrA == *ptrB) {
    return 1;
  } else {
    return 0;
  }
}

int cmpString(void *a, void *b) {
  char *ptrA, *ptrB;
  ptrA = (char *)a;
  ptrB = (char *)b;
  if (!(strcmp(ptrA, ptrB))==1) {
    return 1;
  } else {
    return 0;
  }
}

void format(char *frase,int num){
  int rowlen=60;
  int fraselen=strlen(frase)-1;
  int num_lados=(rowlen-fraselen)/2;
  if(!(strcmp(frase,"-"))==1){
    for(int i=0;i<num;i++){
    printf("------------------------------------------------------------\n\n");
    }
  }
  else{
    if(fraselen%2==0){
      for(int i=0;i<num;i++){
    for(int i=0;i<num_lados;i++){
       printf("-"); 
    }
    printf("%s",frase);
    for(int i=0;i<num_lados;i++){
       printf("-");
    }
    printf("\n\n");
    }
    }
    else{
      for(int i=0;i<num;i++){
      for(int i=0;i<num_lados;i++){
       printf("-"); 
    }
    printf("%s",frase);
    for(int i=-1;i<num_lados;i++){
       printf("-");
    }
      printf("\n\n");
    }
    }
  }
}

void redFormat(char *text,int number){
  printf("\x1b[31m");
  format(text,number);
  printf("\x1b[m");
}

void *formatCreateCofo(){
  int max;
  format("-",1);
  format("CRIAÇÃO DE COFO",1);
  printf("Insira o número máximo de elementos do cofo:\n");
  scanf("%d",&max);
  getchar();

  gCofo *cofo=gcofCreate(max);
  return cofo;
}

int formatDestroyCofo(gCofo* cofo){
  char destruir;
  format("-",1);
  format("DESTRUIÇÃO DE COFO",1);
  printf("Tem certeza de que quer destruir o cofo?: (S/N)\n");
  scanf("%c",&destruir);
  getchar();
  if(destruir=='s' || destruir=='S'){
    return gcofDestroy(cofo);
  }
  else if(destruir=='n' || destruir=='N'){
    return 0;
  }
  else{
    printf("INSIRA UM VALOR VÁLIDO\n");
    return 0;
  }
}

int formatInsertCofo(gCofo *cofo){
  int tipo;
  format("-",1);
  format("INSERIR NO COFO",1);
  printf("Insira o tipo de dado que gostaria de inserir no cofo:\n\n");
  format("[1] - Inteiro",1);
  format("[2] - Flutuante",1);
  format("[3] - Texto",1);
  format("[4] - Aluno",1);
  format("-",1);
  scanf("%d",&tipo);
  getchar();
  
  switch(tipo){
    case 1:
      printf("Insira um número inteiro para adicionar ao cofo:\n");
      int *inteiro=(int *)malloc(sizeof(int));
      scanf("%d",inteiro);
      getchar();
      return gcofInsert(cofo,(void *)inteiro);
      break;
    
    case 2:
      printf("Insira um número racional para adicionar ao cofo:\n");
      float *flutuante=(float *)malloc(sizeof(float));
      scanf("%f",flutuante);
      getchar();
      return gcofInsert(cofo,(void *)flutuante);
      break;
    
    case 3:
      printf("Insira um texto para adicionar ao cofo:\n");
      char *texto=(char *)malloc(sizeof(char)*30);
      scanf("%s",texto);
      getchar();
      return gcofInsert(cofo,(void *)texto);
      break;
    
    case 4:
      printf("Insira uma matrícula para adicionar ao cofo:\n");
      Aluno *aluno=(Aluno *)malloc(sizeof(aluno));

      
      int *matricula=(int *)malloc(sizeof(int));
      scanf("%d",matricula);
      getchar();
      printf("Insira o nome completo do aluno para adicionar ao cofo:\n");
      // char *nome=(char *)malloc(sizeof(char)*30);
      scanf("%s",aluno->nome_completo);
      getchar();
      printf("Insira um coeficiente de rendimento para adicionar ao cofo:\n");
      float *cr=(float *)malloc(sizeof(float));
      scanf("%f",cr);
      getchar();

      // Aluno aluno={*matricula, *nome, *cr};
      aluno->matricula=*matricula;
      aluno->cr=*cr;
      return gcofInsert(cofo,(void *)aluno);
      break;
  }
  return 0;
}

/*int formatGetFirstCofo(gCofo *cofo){
  printf("PRIMEIRO ELEMENTO DO COFO:\n");
  void *first=gcofGetFirst(cofo);
  // cmpInt(void *a, void *b)
}
int formatGetNextCofo(gCofo *cofo){
  void *first=gcofGetNext(cofo);
  printf("ELEMENTO %d DO COFO:\n",cofo->atual);
}*/


int formatQueryCofo(gCofo *cofo){
  int tipo;
  format("-",1);
  format("PROCURAR NO COFO",1);
  printf("Insira o tipo de dado que gostaria de procurar no cofo:\n\n");
  format("[1] - Inteiro",1);
  format("[2] - Flutuante",1);
  format("[3] - Texto",1);
  format("[4] - Aluno",1);
  format("-",1);
  scanf("%d",&tipo);
  getchar();
  switch(tipo){
    case 1:
      printf("Insira um inteiro para procurar no cofo:\n");
      int inteiro;
      scanf("%d",&inteiro);
      getchar();
      int *dadoInt=(int *)malloc(sizeof(int));
      if(dadoInt==NULL){
        printf("ERRO\n");
        break;
      }
      dadoInt[0]=inteiro;
      void *ptrDadoInt=(void *)dadoInt;
      void *cofoQueryInt=gcofQuery(cofo, ptrDadoInt, cmpInt);
      if(cofoQueryInt==NULL){
        printf("Ocorreu um erro ou o inteiro não está no cofo\n");
        break;
      }
      int queryInt= *(int *)cofoQueryInt;
      if(queryInt==inteiro){
        printf("O inteiro está presente no cofo\n");
        return 1;
      }
      else{
        printf("O inteiro NÃO está presente no cofo\n");
        return 0;
      }
      break;
    
    case 2:
      printf("Insira um número racional para procurar no cofo:\n");
      float flutuante;
      scanf("%f",&flutuante);
      getchar();
      float *dadoFloat=(float *)malloc(sizeof(float));
      if(dadoFloat==NULL){
        printf("ERRO\n");
        break;
      }
      dadoFloat[0]=flutuante;
      void *ptrDadoFloat=(void *)dadoFloat;
      void *cofoQueryFloat=gcofQuery(cofo, ptrDadoFloat, cmpFloat);
      if(cofoQueryFloat==NULL){
        printf("Ocorreu um erro ou o número racional não está no cofo\n");
        break;
      }
      float queryFloat = *(float *)cofoQueryFloat;
      if(queryFloat==flutuante){
        printf("O número racional está presente no cofo\n");
        return 1;
      }
      else{
        printf("O número racional NÃO está presente no cofo\n");
        return 0;
      }
    break;
    
    case 3:
      printf("Insira um texto para procurar no cofo:\n");
      char texto[30];
      scanf("%s",texto);
      getchar();
      char *dadoString=(char *)malloc(sizeof(char)*30);
      if(dadoString==NULL){
        printf("ERRO\n");
        break;
      }
      strcpy(dadoString,texto);
      void *ptrDadoString=(void *)dadoString;
      void *cofoQueryString=gcofQuery(cofo, ptrDadoString, cmpString);
      if(cofoQueryString==NULL){
        printf("Ocorreu um erro ou o texto não está no cofo\n");
        break;
      }
      char *queryString= (char *)cofoQueryString;
      if(!(strcmp(queryString, texto))==1){
        printf("O texto está presente no cofo\n");
        return 0;
      }
      else{
        printf("O texto NÃO está presente no cofo\n");
        return 1;
      }
    break;
    
    case 4:
      printf("Insira uma matrícula para adicionar ao cofo:\n");
      Aluno *aluno=(Aluno *)malloc(sizeof(aluno));

      int *matricula=(int *)malloc(sizeof(int));
      scanf("%d",matricula);
      getchar();
      printf("Insira o nome completo do aluno para adicionar ao cofo:\n");
      // char *nome=(char *)malloc(sizeof(char)*30);
      scanf("%s",aluno->nome_completo);
      getchar();
      printf("Insira um coeficiente de rendimento para adicionar ao cofo:\n");
      float *cr=(float *)malloc(sizeof(float));
      scanf("%f",cr);
      getchar();

      // Aluno aluno={*matricula, *nome, *cr};
      aluno->matricula=*matricula;
      aluno->cr=*cr;

      if(aluno==NULL){
        printf("ERRO\n");
        break;
      }
      void *ptrAluno=(void *)aluno;
      void *cofoQueryAluno=gcofQuery(cofo, ptrAluno, cmpAluno);
      if(cofoQueryAluno==NULL){
        printf("Ocorreu um erro ou o aluno não está no cofo\n");
        break;
      }
      Aluno *queryAluno = (Aluno *)cofoQueryAluno;
      printf("matricula = %d\n",aluno->matricula);
      printf("matricula query = %d\n",queryAluno->matricula);
      printf("cr = %f\n",aluno->cr);
      printf("cr query = %f\n",queryAluno->cr);
      printf("nome = %s\n",aluno->nome_completo);
      printf("nome query = %s\n",queryAluno->nome_completo);
      if(queryAluno->matricula==aluno->matricula && queryAluno->cr==aluno->cr && !(strcmp(queryAluno->nome_completo,aluno->nome_completo))==1){
        printf("O aluno está presente no cofo\n");
        return 1;
      }
      else{
        printf("O aluno NÃO está presente no cofo\n");
        return 0;
      }
    break;
  }
  return 0;
}





int formatRemoveCofo(gCofo *cofo){
  int tipo;
  format("-",1);
  format("REMOVER DO COFO",1);
  printf("Insira o tipo de dado que gostaria de remover do cofo:\n\n");
  format("[1] - Inteiro",1);
  format("[2] - Flutuante",1);
  format("[3] - Texto",1);
  format("[4] - Aluno",1);
  format("-",1);
  scanf("%d",&tipo);
  getchar();
  switch(tipo){
    case 1:
      printf("Insira um inteiro para remover do cofo:\n");
      int inteiro;
      scanf("%d",&inteiro);
      getchar();
      int *dadoInt=(int *)malloc(sizeof(int));
      if(dadoInt==NULL){
        printf("ERRO\n");
        break;
      }
      dadoInt[0]=inteiro;
      void *ptrDadoInt=(void *)dadoInt;
      void *cofoRemoveInt=gcofRemove(cofo, ptrDadoInt, cmpInt);
      if(cofoRemoveInt==NULL){
        printf("Ocorreu um erro ou o inteiro não está no cofo\n");
        break;
      }
      int removeInt= *(int *)cofoRemoveInt;
      if(removeInt==inteiro){
        printf("O inteiro foi removido do cofo\n");
        return 1;
      }
      else{
        printf("O inteiro NÃO está presente no cofo\n");
        return 0;
      }
      break;
    
    case 2:
      printf("Insira um número racional para remover do cofo:\n");
      float flutuante;
      scanf("%f",&flutuante);
      getchar();
      float *dadoFloat=(float *)malloc(sizeof(float));
      if(dadoFloat==NULL){
        printf("ERRO\n");
        break;
      }
      dadoFloat[0]=flutuante;
      void *ptrDadoFloat=(void *)dadoFloat;
      void *cofoRemoveFloat=gcofRemove(cofo, ptrDadoFloat, cmpFloat);
      if(cofoRemoveFloat==NULL){
        printf("Ocorreu um erro ou o número racional não está no cofo\n");
        break;
      }
      float removeFloat = *(float *)cofoRemoveFloat;
      if(removeFloat==flutuante){
        printf("O número racional foi removido do cofo\n");
        return 1;
      }
      else{
        printf("O número racional NÃO está presente no cofo\n");
        return 0;
      }
    break;
    
    case 3:
      printf("Insira um texto para remover do cofo:\n");
      char texto[30];
      scanf("%s",texto);
      getchar();
      char *dadoString=(char *)malloc(sizeof(char)*30);
      if(dadoString==NULL){
        printf("ERRO\n");
        break;
      }
      strcpy(dadoString,texto);
      void *ptrDadoString=(void *)dadoString;
      void *cofoRemoveString=gcofRemove(cofo, ptrDadoString, cmpString);
      if(cofoRemoveString==NULL){
        printf("Ocorreu um erro ou o texto não está no cofo\n");
        break;
      }
      char *removeString= (char *)cofoRemoveString;
      if(!(strcmp(removeString, texto))==1){
        printf("O texto foi removido do cofo\n");
        return 0;
      }
      else{
        printf("O texto NÃO está presente no cofo\n");
        return 1;
      }
    break;
    
    case 4:
      printf("Insira uma matrícula para remover do cofo:\n");
      Aluno *aluno=(Aluno *)malloc(sizeof(aluno));

      int *matricula=(int *)malloc(sizeof(int));
      scanf("%d",matricula);
      getchar();
      printf("Insira o nome completo do aluno para remover do cofo:\n");
      // char *nome=(char *)malloc(sizeof(char)*30);
      scanf("%s",aluno->nome_completo);
      getchar();
      printf("Insira um coeficiente de rendimento para remover do cofo:\n");
      float *cr=(float *)malloc(sizeof(float));
      scanf("%f",cr);
      getchar();

      // Aluno aluno={*matricula, *nome, *cr};
      aluno->matricula=*matricula;
      aluno->cr=*cr;

      if(aluno==NULL){
        printf("ERRO\n");
        break;
      }
      void *ptrAluno=(void *)aluno;
      void *cofoRemoveAluno=gcofRemove(cofo, ptrAluno, cmpAluno);
      if(cofoRemoveAluno==NULL){
        printf("Ocorreu um erro ou o aluno não está no cofo\n");
        break;
      }
      Aluno *removeAluno = (Aluno *)cofoRemoveAluno;
      printf("matricula = %d\n",aluno->matricula);
      printf("matricula query = %d\n",removeAluno->matricula);
      printf("cr = %f\n",aluno->cr);
      printf("cr query = %f\n",removeAluno->cr);
      printf("nome = %s\n",aluno->nome_completo);
      printf("nome query = %s\n",removeAluno->nome_completo);
      if(removeAluno->matricula==aluno->matricula && removeAluno->cr==aluno->cr && !(strcmp(removeAluno->nome_completo,aluno->nome_completo))==1){
        printf("O aluno foi removido do cofo\n");
        return 1;
      }
      else{
        printf("O aluno NÃO está presente no cofo\n");
        return 0;
      }
    break;
  }
  return 0;
}

void caseFunction(){
  int number;
  int thereIsCofo=0;
  gCofo *cofo=NULL;
  while(1){
    printf("Pressione:\n\n");
    if(thereIsCofo==0){
  format("[1] - Criar cofo genérico",1);
    } 
    else{
  redFormat("[1] - Criar cofo genérico",1);
      }
  if(thereIsCofo==1 && cofo->numItens==0){
  format("[2] - Destruir cofo genérico",1);
  }
    else{
      redFormat("[2] - Destruir cofo genérico",1);
    }
  if(thereIsCofo==1 && cofo->numItens<cofo->maxItens){
  format("[3] - Inserir item no cofo genérico",1);
  }
    else{
      redFormat("[3] - Inserir item no cofo genérico",1);
    }
  //   if(thereIsCofo==1 && cofo->numItens>0){
  // format("[4] - Listar os elementos do cofo genérico",1);
  //   } else{
  //     redFormat("[4] - Listar os elementos do cofo genérico",1);
  //   }
    
    /*if(thereIsCofo==1 && cofo->numItens > 0 && cofo->atual < cofo->numItens - 1){
  format("[5] - Pegar o próximo elemento do cofo genérico",1);
    } else{
      redFormat("[5] - Pegar o próximo elemento do cofo genérico",1);
    }*/
    if(thereIsCofo==1 && cofo->numItens>0){
  format("[4] - Consultar elemento do cofo genérico",1);
  format("[5] - Remover elemento do cofo genérico",1);
  } 
  else{
  redFormat("[4] - Consultar elemento do cofo genérico",1);
  redFormat("[5] - Remover elemento do cofo genérico",1);
  }
  format("[6] - Finalizar programa",1);

  scanf("%d",&number);
  getchar();
    
  switch(number){
    case 1:
    if(thereIsCofo==0){
        cofo=formatCreateCofo();
      if(cofo!=NULL){
        thereIsCofo=1;
      }
    }
    break;
    
    case 2:
    if(thereIsCofo==1 && cofo!=NULL){
      if(cofo->numItens==0){
        if(formatDestroyCofo(cofo)==1){
        thereIsCofo=0;
      }
    } else{
        printf("O COFO PRECISA ESTAR VAZIO PARA SER DESTRUÍDO\n");
    }
    }
    break;
    
    case 3:
    if(thereIsCofo==1){
      if(cofo->numItens < cofo->maxItens){
        formatInsertCofo(cofo);
      }
      else{
        printf("O COFO ESTÁ CHEIO\n");
      }
    }
    break;
    
    // case 4:
    // if(thereIsCofo==1){
    //   if(cofo->numItens>0){
    // //k
    //   }
    //   else{
    //     printf("O COFO NÃO POSSUI ELEMENTOS\n");
    //   }
    // }
    // break;
    
    case 4:
    if(thereIsCofo==1 && cofo->numItens>0){
    formatQueryCofo(cofo);
    }
    break;
    
    case 5:
    if(thereIsCofo==1){
    formatRemoveCofo(cofo);
    }
    break;

    case 6:
    printf("Obrigado e volte sempre!");
    return;
    
    default:
      printf("INSIRA UM VALOR VÁLIDO!\n");
    break;
    }
  }
}

int main(void) {
  format("-",3);
  format("TAD GENÉRICO",1);
  format("-",3);
  caseFunction();
  
  gCofo *gcofo = gcofCreate(3);
  Aluno andrei = {7, "Andrei Ramos Lopes", 8.5};
  Aluno carlos = {4, "Carlos Eduardo Veras Gomes", 3.7};
  int num=76;
  Aluno ingrid = {1, "Ingrid Coelho Carvalho Muzy", 10.1};
  gcofInsert(gcofo, (void *)&andrei);
  gcofInsert(gcofo, (void *)&carlos);
  gcofInsert(gcofo, (void *)&num);
  gcofInsert(gcofo, (void *)&ingrid);
  // printf("%d\n",(*(int *)gcofQuery(gcofo, (void *)&carlos, cmpAluno)));
  // printf("%d\n",(*(int *)gcofRemove(gcofo, (void *)&carlos, cmpAluno)));
  // printf("Hello World!\n");
  return 0;
}