// the left child node of current node at index i is at 2*i +1
// the right child node of current node at index i is at 2*i + 2
// let current node be at index i then parent node is at (i - 1)/2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000

// struct to encaptulate the array and index into single data type 
typedef struct binary_heap{
    int q[MAX]; // array where the binary heap will be stored
    int ci; // current index where the insertion must happen to preserve the heap invariant
}bh;

typedef struct bogo{
    int val; // stores the value 
    int i; // stores the index
}vi;
// for swapping values at given indices of the heap
void swap(bh *heap,vi* parent, vi* child){
    // following swaps values inside the heap between current child and current parent
    int temp = heap->q[parent->i];
    heap->q[parent->i] = heap->q[child->i];
    heap->q[child->i] = temp;
    // following updates the index of th parent and child accordingly
    // temp = child->i;
    // child->i = parent->i;
    // parent->i = temp;
}
// for displaying binary heap to a given level
void display(bh* heap){
    for (int i = 0;i < heap->ci; i++){
        printf("%d",heap->q[i]);
    }
    puts(" ");
}
// comparision function
// to compare the parent to child node
// modify it accordingly to get MIN heap or MAX heap
bool compare(vi parent,vi child){
    return parent.val >= child.val; // max heap
    // return parent.val <= child.val; // min heap
}
// returns the value and index of parent node defined by current index
vi get_parent(bh *heap, int index){
    vi parent;
    parent.i = (index - 1)/2;
    parent.val = heap->q[parent.i];
    return parent;
}
void swim(bh* heap,int i){
    if (i == 0) return;
    else {
        vi c_child = {heap->q[i],i};
        vi c_parent = get_parent(heap,i);
        while ( !compare(c_parent,c_child)){
            swap(heap,&c_parent,&c_child);
            c_child.val = c_parent.val;
            c_parent = get_parent(heap,c_child.i);
            printf("p = %d, %d; c = %d, %d\n",c_parent.val,c_parent.i,c_child.val,c_child.i);
        }
        swim(heap,c_parent.i);
    }
}
void insert(bh *heap, int item){
    // check if space is available
    if (heap->ci >= MAX){
        printf("heap overflow\n");
        return;
    }
    // first insert into current c_i
    heap->q[heap->ci] = item;
    heap->ci = heap->ci +1;

    vi c_child = {item,heap->ci-1};            // current child
    vi c_parent = get_parent(heap,c_child.i);  // current parent

    // check if heap invariant is preserved
    // if not then modify the code accordingly
    display(heap);
    swim(heap,c_child.i);
    printf("p = %d, %d; c = %d, %d\n",c_parent.val,c_parent.i,c_child.val,c_child.i);
    // printf("child %d pare %d\n",c_child.i,c_parent.i);
    // swap(heap,&c_parent,&c_child);
}

int main(){
    bh *h = malloc(sizeof(bh)); 
    h->ci = 0;
    insert(h,1);
    insert(h,2);
    insert(h,3);
    insert(h,4);
    insert(h,5);
    insert(h,6);
    insert(h,7);
    insert(h,8);
    insert(h,9);
    insert(h,10);
    // insert(h,3);
    // insert(h,4);
    // insert(h,2);
    // insert(h,1);
    // insert(h,4);
    // insert(h,3);
    // insert(h,5);

    display(h);
    free(h);
}