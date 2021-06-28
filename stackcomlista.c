#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 500
typedef struct Stack stack;
typedef struct Node node;

struct Node{
    int value;
    node *next;
};

struct Stack{ 
    node *top;       
};

stack *create_stack(){
    stack* new_stack = (stack *) malloc(sizeof(stack)); 
    new_stack->top = NULL;
    return new_stack;
}

node* pop(stack* pilha){ // remove
    if(pilha->top == NULL) return NULL;
    node* aux = pilha->top;
    pilha->top = pilha->top->next;
    aux->next = NULL;
    return aux;
} 

void push(stack* pilha, int value){ //add um elemento 
    node* new_top = (node*) malloc(sizeof(node));
    new_top->value = value;
    new_top->next = pilha->top;
    pilha->top = new_top;
}
        
int peek(stack* pilha){ // retorna um elemento sem tirar ele da lista
    if(pilha->top == NULL) return -1;
    return pilha->top->value; 
}

int main(){
    stack *pilha = create_stack();  
    
    int n = 4;
    while(n != 0){
        scanf("%d", &n);
        push(pilha, n);
    }

    peek(pilha); 
}