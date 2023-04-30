typedef struct _stack_ Stack;
Stack *stkCreate(int max);
int stkPush(Stack *s, void *elm);
void *stkPop(Stack *s);
int stkIsEmpty(Stack *s);
int stkDestroy(Stack *s);
int Epalindromo(char *, int n);
typedef struct _stack_ {
  int maxItens;
  int top;
  void **item;
} Stack;