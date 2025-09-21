#include <stdio.h>
#include <stdlib.h>

#include "avl_tree.h"

//allocation of structure containing root of avl
avl_t* createAvl(){
    avl_t *avl = malloc(sizeof(avl_t));
    avl->root = NULL;
    return avl;
}
// inserting into avl 
// just plain insertion, no balancing
void insertAvl_inner(node_t *node, node_t *newnode){
    // if duplicates values is inserted then we try to insert it toward right
    if (node->data <= newnode->data){
        if (node->right == NULL){
            node->right = newnode;
            newnode->parent = node;
        }
        else
            insertAvl_inner(node->right,newnode); // insert to right of node
    }
    else {// case: node->data > newnode->data
        if (node->left == NULL){
            node->left = newnode;
            newnode->parent = node;
        }
        else
            insertAvl(node->left,newnode); // insert to left of node
    }
}
// wrapper function for inserting into avl
// it also does necessary rotations to maintain bf between -1 and 1
void insertAvl(avl_t *avl,int data){
    // allocate space for new node
    node_t *newnode = malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->h = 0;

    // avl is empty
    if (avl->root == NULL){
        avl->root = newnode;
        return;
    }
    // avl is non empty
    insertAvl(avl->root,newnode);
    // update the height
    newnode = newnode->parent;
    while (newnode != NULL){
        newnode->h = newnode->h +1;
        newnode = newnode->parent;
    }
    // TO DO: do the required rotations to preserve the avl invariant
}
// for printing inorderly fashion
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
// for printing in preorderly fashion
void printPreoder(node_t *node){
    // node is empty
    if (node == NULL) return;
    printf("%d ",node->data);
    // traverse left of the current node
    printPreorder(node->left);
    // traverse right of the current node
    printPreorder(node->right);
}
// for printing in postorderly fashion
void printPostoder(node_t *node){
    // node is empty
    if (node == NULL) return;
    // traverse left subtree of current node
    printPostorder(node->left);
    // traverse right subtree of current node
    printPostorder(node->right);
    // print value of current node
    printf("%d ",node->data);
}
// delete all nodes of avl
void free_nodes(node_t *node){
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
// free the avl 
void freeAvl(avl_t *avl){
    // when space for bst is not allocated
    if (avl == NULL) return;
    // free all nodes of the bst
    free_node(avl->root);
    // free the bst's data structure
    free(avl);
}
// find the successor node's value
int successor(node_t *node,int which_child){
    // when which_child is 0 then we find left successor
    // else we find right successor
    node_t *trav;
    if (which_child == 0){
        // find the node with largest value in the left subtree
        trav = node->left;
        if (trav->right == NULL) // when left subtree has no right node
            return trav->data;
        while (trav->right->left != trav->right->right) // both nodes will point to same address when both of them is NULL
            trav = trav->right;
    }
    else {
        // find the node with smallest value in the right subtree
        trav = node->right;
        if (trav->left == NULL) // when right subtree has no left node
            return trav->data;
        while (trav->left->left != trav->left->right)
            trav = trav->left;
    }
    return trav->data;
}
// for deleting specific data element if it exists
// returns address of parent node of deleted node - for updating height of nodes
node_t* deleteNode(node_t *node,int data){
    // check if null node
    if (node == NULL){
        puts("Element not found\nCannot delete");
        return NULL;
    }
    node_t *deleted;
    // node to be deleted is a leaf node
    if (node->data == data && node->left == NULL && node->right == NULL){// could also do node->left == node->right as both will be equal only for NULL
        // to be deleted node is left child of its parent 
        if (node->parent->left == node) node->parent->left = NULL;
        // to be deleted node is right child of its parent
        else node->parent->right = NULL;
        deleted = node;
        free(deleted);
        return node->parent;
    } 
    // node to be deleted has left subtree only
    else if (node->data == data && node->left != NULL && node->right == NULL){
        // node to be deleted is left of node's parent
        if (node->parent->left == node) node->parent->left = node->left;
        // node to be deleted is right of node's parent
        else node->parent->right = node->left;
        deleted = node;
        free(node);
        return node->parent;
    }
    // node to be deleted has right subtree only
    else if (node->data == data && node->left == NULL && node->right != NULL){
        // node to be deleted is left of node's parent
        if (node->parent->left == node) node->parent->left = node->right;
        // node to be deleted is right of node's parent
        else node->parent->right = node->right;
        deleted = node;
        free(node);
        return node->parent;
    }
    // node to be deleted has both left and right subtrees
    else if (node->data == data && node->left != NULL && node->right == NULL){
        // find left or right successor - we choose left successor
        // then we set current node's value with its successor, then we delete the successor, by calling this function recursively
        int successor_val = successor(node,0);
        node->data = successor_val;
        // edge case : the node's immediate left child is successor - because we are considering left child as successor
        if (node->left->data == successor_val){
            node_t *deleted = node->left;
            node->left = deleted->left;
            free(deleted);
            return node;
        }
        deleteNode(node->left,successor_val);
    }
    // traverse the tree to find the node to be deleted
    else{
        if (node->data < data) deleteNode(node->right,data);
        else deleteNode(node->left,data);
    }
}
// wrapper function for deleting particular node with specific value in the avl
void deleteAvl(avl_t *avl,int val){
    // root node is to be deleted which is also leaf node
    if (avl->root->data == val && avl->root->left == avl->root->right){
        free(avl->root);
        avl->root = NULL;
        return;
    }
    // update the heights -- starting from parent of deleted to root
    node_t *parent_of_deleted = deleteNode(avl->root,val);
    while (parent_of_deleted != NULL){
        parent_of_deleted->h = parent_of_deleted->h -1;
        parent_of_deleted = parent_of_deleted->parent;
    }
    // TO DO: do the required rotations to preserve the avl invariant
}
// breadth first printing of value of nodes
void level_order_traversal(node_t *node){
    return;
}
