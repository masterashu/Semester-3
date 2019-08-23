#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    char color;
    struct node *parent;
    struct node *left, *right;
} Node;

Node* uncle(Node* node){
    Node *parent = node->parent, *gp = node->parent->parent;
    if (gp->left == parent) {
        return gp->right;
    }
    else {
        return gp->left;
    }
}

Node* create_node(int val, char color, Node* parent){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->color = color;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL; 
    return new;
}

Node* insert_node(Node* root, Node* new_node){
    // When the Tree is empty
    if (root == NULL){
        // root is Black
        return new_node;
    }
    else{
        // Finding position (Binary Search Property):
        if (new_node->val < root->val){
            // Insert in Left Subtree
            root->left = insert_node(root->left, new_node);
            root->left->parent = root;
        } else {
            // Insert in Right Subtree
            root->right = insert_node(root->right, new_node);
            root->right->parent = root;
        }
    }
    return root;
}

void rotate_left(Node** HEAD, Node** NEW_NODE){
    // Temp Variables
    Node *head = *HEAD, *new_node = *NEW_NODE;

    Node *new_right = new_node->right;
    new_node->right = new_right->left;

    if (new_node->right != NULL){
        new_node->right->parent = new_node;
    }
    new_right->parent = new_node->parent;

    if (new_node->parent == NULL){
        head = new_right;
    } 
    else if(new_node == new_node->parent->left){
        new_node->parent->left = new_right;
    }
    else{
        new_node->parent->right = new_right;
    }
    new_right->left = new_node;
    new_node->parent = new_right;
    
    // Update Values
    *NEW_NODE = new_node;
    *HEAD = head;
}

void rotate_right(Node** HEAD, Node** NEW_NODE){
    // Temp Variables
    Node *head = *HEAD, *new_node = *NEW_NODE;

    Node *new_right = new_node->left; 
  
    new_node->left = new_right->right; 
  
    if (new_node->left != NULL) 
        new_node->left->parent = new_node; 
  
    new_right->parent = new_node->parent; 
  
    if (new_node->parent == NULL) 
        head = new_right; 
  
    else if (new_node == new_node->parent->left) 
        new_node->parent->left = new_right; 
  
    else
        new_node->parent->right = new_right; 
  
    new_right->right = new_node; 
    new_node->parent = new_right; 
    
    // Update Values
    *NEW_NODE = new_node;
    *HEAD = head;
}

void fix_tree(Node** HEAD, Node** NEW_NODE){
    // Temp Variables
    Node *head = *HEAD, *new_node = *NEW_NODE;

    Node *parent_pt = NULL; 
    Node *grand_parent_pt = NULL; 
  
    while ((new_node != head) && (new_node->color != 'b') && 
           (new_node->parent->color == 'r')) 
    { 
  
        parent_pt = new_node->parent; 
        grand_parent_pt = new_node->parent->parent; 
  
        /*  Case : A 
            Parent of new_node is left child of Grand-parent of new_node */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Node *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of new_node is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == 'r') 
            { 
                grand_parent_pt->color = 'r'; 
                parent_pt->color = 'b'; 
                uncle_pt->color = 'b'; 
                new_node = grand_parent_pt; 
            } 
  
            else
            { 
                /* Case : 2 
                   new_node is right child of its parent 
                   Left-rotation required */
                if (new_node == parent_pt->right) 
                { 
                    rotate_left(&head, &parent_pt); 
                    new_node = parent_pt; 
                    parent_pt = new_node->parent; 
                } 
  
                /* Case : 3 
                   new_node is left child of its parent 
                   Right-rotation required */
                rotate_right(&head, &grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                new_node = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of new_node is right child of Grand-parent of new_node */
        else
        { 
            Node *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of new_node is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 'r')) 
            { 
                grand_parent_pt->color = 'r'; 
                parent_pt->color = 'b'; 
                uncle_pt->color = 'b'; 
                new_node = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   new_node is left child of its parent 
                   Right-rotation required */
                if (new_node == parent_pt->left) 
                { 
                    rotate_right(&head, &parent_pt); 
                    new_node = parent_pt; 
                    parent_pt = new_node->parent; 
                } 
  
                /* Case : 3 
                   new_node is right child of its parent 
                   Left-rotation required */
                rotate_left(&head, &grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                new_node = parent_pt; 
            } 
        } 
    } 
  
    head->color = 'b';
        // Update Values
    *NEW_NODE = new_node;
    *HEAD = head;
}



int main(){
    printf("Hello!\n");
    Node* Head = NULL;
    int arr[10] = {76, 38, 32, 53, 64, 14, 56 ,35 ,34, 12};
    for (int i = 0; i < 10; i++){
        Node* new = create_node(arr[i], 'r', NULL);
        Head = insert_node(Head, new);
        fix_tree(&Head, &new);
    }
    return 0;
}
