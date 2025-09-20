// binary tree using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// struct to encaptulate the array which stores the data of the binary tree 
// 0 is used for checking if we have initialized an array index or not
typedef struct binary_tree{
    int q[MAX]; // array where the binary heap will be stored
}bt_t;

typedef struct bogo{
    int val; // stores the value 
    int i; // stores the index
}vi;
// get index and value of the parent node by giving index of current node - currently not required
vi get_parent(bt_t *bt, int index){
    vi parent;
    parent.i = (index - 1)/2;
    parent.val = bt->q[parent.i];
    return parent;
}
// left child
vi get_child_left(bt_t *bt,int index){
    vi left;
    left.i = 2*index +1;
    left.val = bt->q[left.i];
    return left;
}
// right child
vi get_child_right(bt_t *bt,int index){
    vi right;
    right.i = 2*index +2;
    right.val = bt->q[right.i];
    return right;
}
// helper function for inserting node
void insert_inner(bt_t *bt,vi node,int item){
    // check for index out of bounds
    if (node.i >= MAX) {
        puts("index out of bounds");
        return;
    }
    // current node is unoccupied
    if (node.val == 0){
        bt->q[node.i] = item;
    }
    // current node has value less than item to be inserted - so insert into right subtree of current node
    else if (node.val < item){
        insert_inner(bt,get_child_right(bt,node.i),item);
    }
    // current node has value more than or equal to item to be inserted - so insert into left subtree of current node
    else if (node.val >= item){
        insert_inner(bt,get_child_left(bt,node.i),item);
    }
}
// for inserting value into the bt - a wrapper function
void insert(bt_t *bt, int item){
    vi node = {bt->q[0],0};
    insert_inner(bt,node,item);
}

// printing elements of the bs tree by traversing inorderly
void printInorder(bt_t *bt,int i){
    // check for index out of bounds
    if (i >= MAX) {
        puts("index out of bounds");
        return;
    }
    // node is empty
    if (bt->q[i]== 0) return;
    // traverse to left of bst
    printInorder(bt,2*i+1);
    // print current node's value
    printf("%d ",bt->q[i]);
    // traverse right of bst
    printInorder(bt,2*i+2);
}
// printing elements of the bs tree by traversing preorderly
void printPreorder(bt_t *bt,int i){
    // check for index out of bounds
    if (i >= MAX) {
        puts("index out of bounds");
        return;
    }
    // node is empty
    if (bt->q[i]== 0) return;
    printf("%d ",bt->q[i]);
    // traverse left of the current node
    printPreorder(bt,2*i+1);
    // traverse right of the current node
    printPreorder(bt,2*i+2);
}
// printing elements of the tree by traversing postorderly
void printPostorder(bt_t *bt,int i){
    // check for index out of bounds
    if (i >= MAX) {
        puts("index out of bounds");
        return;
    }
    // node is empty
    if (bt->q[i]== 0) return;
    // traverse left subtree of current node
    printPostorder(bt,2*i+1);
    // traverse right subtree of current node
    printPostorder(bt,2*i+2);
    // print value of current node
    printf("%d ",bt->q[i]);
}
int main(){
    bt_t *bt = malloc(sizeof(bt_t));
    insert(bt,11);      
    insert(bt,6);
    insert(bt,15);
    insert(bt,3);
    insert(bt,8);
    insert(bt,13);
    insert(bt,17);
    insert(bt,1);
    insert(bt,5);
    insert(bt,12);
    insert(bt,14);
    insert(bt,19);

    printInorder(bt,0);
    puts("");
    printPreorder(bt,0);
    puts("");
    printPostorder(bt,0);
    puts("");

    return 0;
}