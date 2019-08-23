#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    char color;
    struct node *parent;
    struct node *left, *right;
} Node;

Node* create_node(int val, char color, Node* parent){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->color = color;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL; 
    return new;
}

Node* insert_node(Node* HEAD, Node* Parent, int num){
    // When the Tree is empty
    if (HEAD == NULL){
        // Head is Black
        if(Parent == NULL){
            return create_node(num, 'b', Parent);    
        } 
        else {
            return create_node(num, 'r', Parent);
        }
    }
    else{
        // Finding position (Binary Search Property):
        if (num < HEAD->val){
            // Insert in Left Subtree
            HEAD->left = insert_node(HEAD->left, HEAD, num);
        }
        else {
            // Insert in Right Subtree
            HEAD->right = insert_node(HEAD->right, HEAD, num);
        }
        // Balancing the Red-Black Tree

    }
    
}

int main(){
    printf("Hello!\n");
    Node* Head = NULL;
    int arr[10] = {76, 38, 32, 53, 64, 14, 56 ,35 ,34, 12};
    for (int i = 0; i < 10; i++){
        Head = insert_node(Head, NULL, arr[i]);
        Head->color = 'b';
    }
    return 0;
}
