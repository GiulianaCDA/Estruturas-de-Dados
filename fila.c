#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct Queue queue;

struct Node{
    int value;
    node *next;  
};

struct Queue{ //fila
    int size;
    node* head;
    node* tail;
};

queue *create_queue(){
    queue* new_queue =  (queue*) malloc(sizeof(queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;
    return new_queue; 
}

void enqueue(queue* queue, int value){
    node* new_node = (node*) malloc(sizeof(node));

    new_node->value = value;
    new_node->next = NULL;

    if(queue->size == 0){
        queue->head = new_node; 
        queue->tail = new_node;
    }
    else{
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;
}

int dequeue(queue* queue){
    if(queue->size == 0) return -1;
    int aux;

    aux = queue->head->value;
    queue->head = queue->head->next;
    queue->size--;

    return aux;
}

int main(){
    queue* new_queue = create_queue();
    enqueue(new_queue, 2);
    enqueue(new_queue, 5);
    enqueue(new_queue, 7);
    
    printf("saiu: %d\n", dequeue(new_queue));
    printf("saiu: %d\n", dequeue(new_queue));
    printf("saiu: %d\n", dequeue(new_queue));

}

