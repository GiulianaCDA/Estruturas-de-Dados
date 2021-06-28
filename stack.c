#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 500
typedef struct Stack stack;

struct Stack{ 
    int size;
    int values[MAX_STACK_SIZE];       
};

stack *create_stack(){
    stack* new_stack = (stack *) malloc(sizeof(stack)); 
    new_stack->size = 0;
    return new_stack;
}
int pop(stack* pilha){
    if(pilha->size == 0) return -1;
    pilha->size--; 
    return pilha->values[pilha->size];  
} 
int push(stack* pilha, int value){
    if(pilha->size == MAX_STACK_SIZE) return -1;
    pilha->values[pilha->size] = value; 
    pilha->size++;
    return 1;
}
int peek(stack* pilha){
    if(pilha->size == 0) return -1;
    return pilha->values[pilha->size - 1]; 
}

int main(){
    stack *pilha = create_stack();  
    
    int n = 4;
    while(n != 0){
        scanf("%d", &n);
        push(pilha, n);
    }

    while(pilha->size > 0){
        printf("%d\n", pop(pilha)); 
    }
    peek(pilha); 
}