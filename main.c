#include <stdio.h>
#include <malloc.h>
////////////////////// Stack for char
typedef struct Stack
{
    char data;
    struct Stack *next;
} Stack;

Stack *push(Stack *stack, char element);
Stack *get(Stack *stack,char *buf);
char check(Stack *stack);
int getSize(Stack *stack);

int main(){
    setbuf(stdout,0);
    Stack *lowStack=NULL;
    Stack *highStack=NULL;
    printf("Enter stack size:\t");
    int size;
    scanf_s("%d",&size);
    printf("Enter characters:\n");
    while (getSize(lowStack)<size && getSize(highStack)<size){
        char buf;
        scanf_s("%c",&buf);
        if(buf>=65 && buf<=90){
            highStack= push(highStack,buf);
        } else if(buf>=97 && buf<=122){
            lowStack= push(lowStack,buf);
        }
    }
    printf("High stack:\n");
    int sizeSt=getSize(highStack);
    for (int i = 0; i <sizeSt ; ++i) {
        char buf;
        highStack=get(highStack,&buf);
        printf("%c ", buf);
    }
    printf("\nLow stack:\n");
    sizeSt=getSize(lowStack);
    for (int i = 0; i < sizeSt; ++i) {
        char buf;
        lowStack=get(lowStack,&buf);
        printf("%c ", buf);
    }
}


Stack *push(Stack *stack, char element) {
    Stack *new= (Stack*)malloc(sizeof(Stack));
    new->next=stack;
    stack=new;
    new->data=element;
}

Stack *get(Stack *stack,char *buf) {
    *buf=stack->data;
    return stack->next;
}

int getSize(Stack *stack) {
    int i=0;
    while (stack!=NULL){
      stack=stack->next;
      ++i;
    }
    return i;
}

char check(Stack *stack) {
    return stack->data;
}

