#include <stdio.h>
#include <stdlib.h>

#define hash_size 13;
typedef struct Node node; 
typedef struct Hashtable hashtable; 

struct Hashtable{
    node* table[hash_size]; 
}
struct Node{
    int key;
    int value;
    node *next;  
};

int is_empty(node *head){
    return (head == NULL);
}

hashtable *create_hashtable(){
    hashtable*  new_ht = (hashtable*) malloc(sizeof(hashtable));  
    for(int i = 0; i < hash_size; i++){
        new_ht->table[i] = create_linked_list();
    }

    return new_ht;
    
}

void put(hashtable* ht, int key, int value){
    int h = key % hash_size; 
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    
    if(ht->table[h] == NULL){
        ht->table[h] = new_node;
    }
    else{
        node* current = ht->table[h];
        while(current->next != NULL){
            current = current->next; 
        }
        current->next = new_node;
    }
} 

int get(hashtable* ht, int key){
    int h = key % hash_size;
    if(ht->table[h] == NULL) return -1; 
    node* current = ht->table[h];

    while(current != NULL){
        if(current->key == key) return current->value; 
        current = current->next;
    }
    return -1;
}

void remove(hashtable* ht, int key){
    int h = key % hash_size;
    node* current = ht->table[h];
    node* previous = NULL;
    while(current != NULL){
        if(current->key == key){ 
            if(previous == NULL){
                node* element = current;
                ht->table[h] = current->next;
                free(element); 
            }
            else{
                previous->next = current->next;
                free(current);
            }
        }

        previous = current;
        current = current->next;
    }
}

int contains_key(hashtable* ht, int key){
    int h = key % hash_size;
    if(ht->table[h] == NULL) return 0; 
    node* current = ht->table[h]; 

    while(current != NULL){
        if(current->key == key) return 1;
        current = current->next;
    } 
    return 0; 
}

void print_hashtable(hashtable* ht){
    for(int i = 0; i < hash_size; i++){
        node* current = ht->table[i];
        while(current != NULL){ 
            printf("%d ", current->value);
            current = current->next;
        }  
        printf("\n");
    }
}

node *create_linked_list(){
    return NULL;
}

int main(){

}