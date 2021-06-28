#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct Queue queue;

struct Node{
    int value;
    int priority;
    node *next;  
};

struct Queue{ //fila
    node* head;
};

queue *create_queue(){
    queue* new_queue =  (queue*) malloc(sizeof(queue));
    new_queue->head = NULL;
    return new_queue; 
}

void enqueue(queue* pq, int value, int p){
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->value = value;
    new_node->priority = p;

    if(pq->head == NULL || p > pq->head->priority){
        new_node->next = pq->head;
        pq->head = new_node;
    }
    else{
        node* current = pq->head;
        while(current->next != NULL && current->next->priority > p){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        
    }
}

node* dequeue(queue* queue){
    if(queue->head == NULL) return NULL;
    node* aux = queue->head;

    queue->head = queue->head->next;
    aux->next = NULL;

    return aux;
}

int main(){
    queue* new_queue = create_queue();
    enqueue(new_queue, 2, 3);
    enqueue(new_queue, 5, 1);
    enqueue(new_queue, 7, 2);
    
    printf("saiu: %d\n", dequeue(new_queue)->value);
    printf("saiu: %d\n", dequeue(new_queue)->value);
    printf("saiu: %d\n", dequeue(new_queue)->value);

}

