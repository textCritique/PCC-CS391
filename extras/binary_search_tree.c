#include <stdio.h>
#include <stdlib.h>

// data structure for node which stores data and reference to left and right child nodes
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node_t;

// data structure for storing root node of binary search tree
typedef struct {
    node_t *root;
}bst_t;

// allocating space for structure containing root
bst_t* createBst(){
    bst_t *bst = malloc(sizeof(bst_t));
    bst->root = NULL;
    return bst;
}

// inserting into bst
void insertBst_inner(node_t *node,node_t *new){
    if (node->data <= new->data){
        if (node->right == NULL)
            node->right = new;
        else
            insertBst_inner(node->right,new); // go to right of current node
    }
    else if (node->data > new->data){
        if (node->left == NULL)
            node->left = new;
        else
            insertBst_inner(node->left,new); // go to left of current node
    }
}
// wrapper function for inserting into bst
void insertBst(bst_t *bst,int data){
    // allocate space for new node
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    // bst is empty
    if (bst->root == NULL){
        bst->root = new;
        return;
    }
    insertBst_inner(bst->root,new);
}
// printing elements of the bs tree by traversing inorderly
void printInorder(node_t *node){
    // node is empty
    if (node == NULL) return;
    // traverse to left of bst
    printInorder(node->left);
    // print current node's value
    printf("%d ",node->data);
    // traverse right of bst
    printInorder(node->right);
}
// printing elements of the bs tree by traversing preorderly
void printPreorder(node_t *node){
    // node is empty
    if (node == NULL) return;
    printf("%d ",node->data);
    // traverse left of the current node
    printPreorder(node->left);
    // traverse right of the current node
    printPreorder(node->right);
}
// printing elements of the tree by traversing postorderly
void printPostorder(node_t *node){
    // node is empty
    if (node == NULL) return;
    // traverse left subtree of current node
    printPostorder(node->left);
    // traverse right subtree of current node
    printPostorder(node->right);
    // print value of current node
    printf("%d ",node->data);
}
// delete whole bst
void free_node(node_t *node){
    // base case- both node is a leaf
    if (node->left == NULL && node->right == NULL)
        free(node);
    
    // current node has only left subtree
    else if (node->left != NULL && node->right == NULL){
        free_node(node->left);
        free(node);
    }
    // current node has only right subtree
    else if (node->right != NULL && node->left == NULL) {
        free_node(node->right);
        free(node);
    }
    // free both left and left subtree
    else {
        free_node(node->left);
        free_node(node->right);
        free(node);
    }
}
// free the bst
void freeBst(bst_t *bst){
    // when space for bst is not allocated
    if (bst == NULL) return;
    // free all nodes of the bst
    free_node(bst->root);
    // free the bst's data structure
    free(bst);
}
int main(){
    bst_t *bst = createBst();
    insertBst(bst,11);
    insertBst(bst,6);
    insertBst(bst,15);
    insertBst(bst,3);
    insertBst(bst,8);
    insertBst(bst,13);
    insertBst(bst,17);
    insertBst(bst,1);
    insertBst(bst,5);
    insertBst(bst,12);
    insertBst(bst,14);
    insertBst(bst,19);

    printInorder(bst->root);
    puts("");
    printPostorder(bst->root);
    puts("");
    printPreorder(bst->root);

    freeBst(bst);
    return 0;
}