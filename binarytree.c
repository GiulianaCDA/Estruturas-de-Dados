#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;


struct Node{
    int value;
    node* left;
    node* right;
};

node* create_binary_tree(int value, node* left, node* right){
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;

    return new_node;  
}

const char* print_binary_tree(node* tree){
    if(tree==NULL) return "()"; 
    char* string = malloc(200001);
    string[0]= '(';
    string[1] = ' ';
    char numbers[1000];
    sprintf(numbers, "%d", tree->value);
    strcat(string, numbers); 
    strcat(string, "  "); 
    strcat(string, print_binary_tree(tree->left)); 
    strcat(string, "  ");
    strcat(string, print_binary_tree(tree->right)); 
    strcat(string, " )"); 
    return string;
}
int main(){
    node* raiz = create_binary_tree(5, NULL, NULL);
    raiz->left = create_binary_tree(2, NULL, NULL);
    raiz->right = create_binary_tree(9, NULL, NULL);
    
    printf("%s\n", print_binary_tree(raiz));
    return 0;
}