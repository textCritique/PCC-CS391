// binary tree using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// struct to encaptulate the array and index into single data type 
typedef struct binary_tree{
    int q[MAX]; // array where the binary heap will be stored
    int ci; // current index where the insertion must happen to preserve the heap invariant
}bt_t;

typedef struct bogo{
    int val; // stores the value 
    int i; // stores the index
}vi;

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
vi get_child_right(bt_t *bt,int index){
    vi right;
    right.i = 2*index +1;
    right.val = bt->q[right.i];
    return right;
}

void insert_inner(bt_t *bt,vi node,int item){
    if (node.val == 0){
        bt->q[node.i] = item;
    }
    else if (node.val < item){
        insert_inner(bt,get_child_right(bt,node.i),item);
    }
    else if (node.val >= item){
        insert_inner(bt,get_child_left(bt,node.i),item);
    }
}
// for inserting value into the bt
void insert(bt_t *bt, int item){
    // check if space is available
    if (bt->ci >= MAX){
        printf("bt overflow\n");
        return;
    }
    
    // bt is empty
    if (bt->q[0] == 0){
        bt->q[0] = item;
    }
    else{
        vi node = {bt->q[0],0};
        insert_inner(bt,node,item);
    }
}

void display(bt_t* bt){
    for (int i = 0;i < MAX; i++){
        printf("%d ",bt->q[i]);
    }
    puts(" ");
}
void printInorder(bt_t *bt,int i){
    if (bt->q[i]== 0) return;
    printf()
}
void printInorder(bt_t *bt,int i){
    // node is empty
    if (bt->q[i]== 0) return;
    // traverse to left of bst
    printInorder(bt,2*i+1);
    // print current node's value
    printf("%d ",node->data);
    // traverse right of bst
    printInorder(bt,2*i+2);
}
// printing elements of the bs tree by traversing preorderly
void printPreorder(bt_t *bt,int i){
    // node is empty
    if (node == NULL) return;
    printf("%d ",node->data);
    // traverse left of the current node
    printPreorder(bt,2*i+1);
    // traverse right of the current node
    printPreorder(bt,2*i+2);
}
// printing elements of the tree by traversing postorderly
void printPostorder(bt_t *bt,int i){
    // node is empty
    if (node == NULL) return;
    // traverse left subtree of current node
    printPostorder(bt,2*i+1);
    // traverse right subtree of current node
    printPostorder(bt,2*i+2);
    // print value of current node
    printf("%d ",node->data);
}
int main(){
    bt_t *bt = malloc(sizeof(bt_t));
    insert(bt,1);      
    insert(bt,2);
    insert(bt,3);
    insert(bt,4);
    insert(bt,5);
    insert(bt,6);
    insert(bt,7);

    display(bt);
}