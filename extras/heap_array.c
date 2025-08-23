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
void swap(bh *heap,int i, int j){
    // following swaps values inside the heap between current child and current parent
    int temp = heap->q[i];
    heap->q[i] = heap->q[j];
    heap->q[j] = temp;
    // we have updated value in the heap only not in the variable because 
    // we only need indices and later we retrive values from original heap
}
// for displaying binary heap in a single line
void display(bh* heap){
    for (int i = 0;i < heap->ci; i++){
        printf("%d ",heap->q[i]);
    }
    puts(" ");
}
// comparision function
// to compare the parent to child node
// modify it accordingly to get MIN heap or MAX heap
bool compare(vi parent,vi child){
    // return parent.val >= child.val; // max heap
    return parent.val <= child.val; // min heap
}
// returns the value and index of parent node defined by current index
vi get_parent(bh *heap, int index){
    vi parent;
    parent.i = (index - 1)/2;
    parent.val = heap->q[parent.i];
    return parent;
}
// makes necessary swaps to move element upward so as to preserve heap invariant
void swim(bh* heap,int i){
    if (i == 0) return; // base case - reached the root
    else {
        vi c_child = {heap->q[i],i};
        vi c_parent = get_parent(heap,i);
        // for checking invariant down the level of parent
        while ( !compare(c_parent,c_child)){
            swap(heap,c_parent.i,c_child.i);
            c_child.val = c_parent.val;        // initially assigned c_parent to c_child - caused bug because child and parent are at their respective indices only value contained therein needs to swapped
            c_parent = get_parent(heap,c_child.i);
            printf("p = %d, %d; c = %d, %d\n",c_parent.val,c_parent.i,c_child.val,c_child.i);
        }
        // for checking invariant one level above the parent
        swim(heap,c_parent.i);
    }
}
// makes necessary swaps to move the element downward to preserve heap invariant
// it returns the index bottomest element which will later used as arg to swim fun inside remove fun
int sink(bh *heap,int i){

    vi parent = {heap->q[i],i};
    vi child_left = {heap->q[2*i+1],2*i+1};
    vi child_right = {heap->q[2*i+2],2*i+2};
    // if there is one child ie child_left
    if (child_left.i == heap->ci -1 ){
        if (!compare(parent,child_left)) swap(heap,parent.i,child_left.i);
        return child_left.i;
    }
    // child doesn't exist for element at i
    else if (child_left.i >= heap->ci){
        return i;
    }
    else {
        // swap parent with child which is least value in the case of MIN heap and vice- versa 
        // swap with left child if there is tie 
        if ((!compare(parent,child_left) || !compare(parent,child_right)) && compare(child_left,child_right)){
            swap(heap,parent.i,child_left.i);
            return sink(heap,child_left.i);
        }
        else if (!compare(parent,child_left) || !compare(parent,child_right)) {
            swap(heap,parent.i,child_right.i);
            return sink(heap,child_right.i);
        }
        else {
            return parent.i;
        }
    }
}
// for removing the root element 
void poll(bh *heap){
    // check if already empty
    if (heap->ci == 0){
        printf("heap underflow\n");
        return;
    }
    // first swap the last elment with the root element
    vi newRoot = {heap->q[heap->ci-1],heap->ci-1};
    vi deletedRoot = {heap->q[0],0};
    swap(heap,deletedRoot.i,newRoot.i);
    // delete the old root
    heap->ci = heap->ci -1;
    // check if heap invariant is preserved
    // if not modify the heap accordingly
    sink(heap,0); // after swap newRoot is at 0
}
// for deleting particular value from heap
void Remove(bh *heap, int item){
    // do a linear search through the array to find the index of item
    int index = -1; // this will be used also as a check
    for (int i = 0; i < heap->ci; i++){
        if (heap->q[i] == item){
            index = i;
            break;
        }
    }
    // check if item exists in heap
    if (index == -1)
        printf("%d does not exist in heap",item);
    
    // first swap the item with element at bottom rigthtest 
    swap(heap,index,heap->ci-1);
    // delete the item
    heap->ci = heap->ci -1;
    // first sink then swim up - to preserve the invariant
    swim(heap,sink(heap,index));
}
// for inserting value into the heap
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
    display(h);
    poll(h);
    display(h);
    Remove(h,6);
    display(h);
    free(h);
    return 0;
}