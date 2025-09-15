#include <stdio.h>
#include <stdlib.h>

// data structure for node
typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node_t;

// data structure for circular circular doubly linked list which holds address of first and last node
typedef struct {
    node_t *head;
    node_t *tail;
}cdll_t;

// allocate memory for cdll_t which will store the head and tail
cdll_t* createCdll(){
    cdll_t *cdll = malloc(sizeof(cdll_t));
    cdll -> head = NULL;
    cdll -> tail = NULL;
    return cdll;
}
int len(cdll_t* cdll){
    // cdll is empty
    if (cdll->head == NULL) return 0;
    int length = 1;
    node_t *trav = cdll->head;
    while (trav != cdll->tail){
        trav = trav->next;
        length++;
    }
    return length;
}
// iterating forward and printing n times
void printFN(cdll_t *cdll,int n){
    // cdll is empty
    if (cdll->head == NULL) return;
    // iterate over n times and print n times
    node_t *trav = cdll->head;
    for (int i = 0; i < n; i++, trav = trav->next)
        printf("%d ",trav->data);
    puts("");
}
// iterating backward and printing n times
void printBN(cdll_t *cdll,int n){
    // cdll is empty
    if (cdll->head == NULL) return;
    // iterate over n times and print n times
    node_t *trav = cdll->tail;
    for (int i = 0; i < n; i++, trav = trav->prev)
        printf("%d ",trav->data);
    puts("");
}
// printing all nodes in forward fashion only once
void printCdll(cdll_t *cdll){
    int n = len(cdll);
    printFN(cdll,n);
}
// printing all nodes in backward fashion only once
void printCdllp(cdll_t *cdll){
    int n = len(cdll);
    printBN(cdll,n);
}
// helper function for free
// recursive function
void freeCdll_inner(node_t *node,node_t *tail){
    // base case - one node ie node next point to itself
    // case of no node is handled is inside outer function
    if (node == tail){
        free(tail);
        return;
    }
    // recursive case - free all node after node then free the node
    freeCdll_inner(node->next,tail);
    free(node);
}
void freeCdll(cdll_t *cdll){
    // cdll contains no node
    if (cdll->head == NULL){
        free(cdll);
        return;
    }
    // cdll is non empty
    // free all nodes
    freeCdll_inner(cdll->head,cdll->tail);
    // free the ccll itself
    free(cdll);
}
// append to cdll
void appendCdll(cdll_t *cdll, int data){
    // allocate memory for a node
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    // cdll contains no node
    if (cdll->head == NULL){
        // connect new node to itself
        new->next = new;
        new->prev = new;
        // assign it to both cdll
        cdll->head = new;
        cdll->tail = new;
        return;
    }
    // cdll contains one or more mode
    // point new node's next to head
    new->next = cdll->head;
    // point new node's prev to tail
    new->prev = cdll->tail;
    // point tail's next to new
    cdll->tail->next = new;
    // point head's prev to new
    cdll->head->prev = new;
    // make new the tail
    cdll->tail = new;
}
// insert at beginning
void insertHeadCdll(cdll_t *cdll, int data){
    // allocate memory for a new node
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    // cdll contains no node
    if (cdll->head == NULL){
        // connect new node to itself
        new->next = new;
        new->prev = new;
        // assign it to both cdll
        cdll->head = new;
        cdll->tail = new;
        return;
    }
    // cdll contains one or more node
    new->next = cdll->head;
    new->prev = cdll->tail;
    
    cdll->head->prev = new;
    cdll->tail->next = new;

    cdll->head = new;
}
// delete from the beginning
void deleteHeadCdll(cdll_t *cdll){
    // cdll is empty
    if (cdll->head == NULL) return;
    // cdll is non empty
    node_t *deleted = cdll->head;

    // point tail's next to head's next 
    cdll->tail->next = cdll->head->next;
    // point node after head 's prev to tail
    cdll->head->next->prev = cdll->tail;
    
    // update the new head to head's next
    cdll->head = cdll->head->next;
    free(deleted);
}
// delete from the end
void deleteTailCdll(cdll_t *cdll){
    // cdll is empty
    if (cdll->head == NULL) return;
    // cdll is non empty
    node_t *deleted = cdll->tail;

    // point node before tall 's next to head
    cdll->tail->prev->next = cdll->head;
    // point head's prev to node before the tail
    cdll->head->prev = cdll->tail->prev;
    // update new tail to node before tail
    cdll->tail = cdll->tail->prev;

    free(deleted);
}
// insert at any pos in the cdll
void insertPosCdll(cdll_t *cdll,int pos, int data){
    // insert at first pos
    if (pos == 1){
        insertHeadCdll(cdll,data);
        return;
    }
    int length = len(cdll);
    // append to cdll
    if (pos == length+1){
        appendCdll(cdll,data);
        return;
    }
    // check for invalid pos
    if (pos > length + 1 || pos < 1){
        puts("not a valid position");
        return;
    }
    // inserting at pos from 2 to length
    node_t *beforePos, *atPos;
    beforePos = cdll->head;
    
    for (int i = 1; i < pos-1; i++, beforePos = beforePos->next);
    atPos = beforePos->next;

    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    // connect beforePos to new and vice versa
    beforePos->next = new;
    new->prev = beforePos;
    // connect new to atPos and vice versa
    new->next = atPos;
    atPos->prev = new;
}
// delete at node at any pos of cdll
void deletePosCdll(cdll_t *cdll,int pos){
    // delete at pos 1 ie head deletion
    if (pos == 1){
        deleteHeadCdll(cdll);
        return;
    }
    int length = len(cdll);
    // delete at last pos ie tail deletion
    if (length == pos){
        deleteTailCdll(cdll);
        return;
    }
    // check for invalid pos
    if (pos > length || pos < 1){
        puts("not a valid positon");
        return;
    }
    // deletion at pos from 2 to length
    node_t *beforePos, *atPos;
    beforePos = cdll->head;
    
    for (int i = 1; i < pos-1; i++,beforePos = beforePos->next);
    atPos = beforePos->next;

    // connect the beforePos to node after atPos and vice versa
    beforePos->next = atPos->next;
    atPos->next->prev = beforePos;

    // delete node after the pos
    free(atPos);
}
int main(){
    cdll_t *cdll = createCdll();

    for (int i = 1; i < 6; i++) insertHeadCdll(cdll,i);

    deleteTailCdll(cdll);
    insertPosCdll(cdll,5,200);
    deletePosCdll(cdll,5);
    printCdll(cdll);
    printFN(cdll,10);
    printBN(cdll,10);
    printCdllp(cdll);
    freeCdll(cdll);
    return 0;
}