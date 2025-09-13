#include <stdio.h>
#include <stdlib.h>

// data structure for node which holds data and address of next node
typedef struct node{
    int data;
    struct node* next;
}node_t;

// data structure for linked list which holds address of first node and last node
typedef struct {
    node_t* head;
    node_t* tail;
}cll_t;

// allocate memory for first node which is going to be head of circular linked list
cll_t* createCll(){
    cll_t* cll = malloc(sizeof(cll_t));
    cll->head = NULL;
    cll->tail = NULL;
    return cll;
}


// no of elements in cll
int len(cll_t* cll){
    // check if cll is empty or not
    if (cll->head == NULL) return 0;

    int length = 1;
    node_t* iter = cll->head;
    while (iter != cll->tail){
        iter = iter->next;
        length++;
    }
    return length;
}
// for printing and traversing till nth time
void printN(cll_t* cll,int n){
    // check if it is empty
    if (cll->head == NULL) return;
    node_t* trav = cll->head;
    for (int i= 0; i < n; i++, trav = trav->next) printf("%d ",trav->data);
    puts("");
}

void printCll(cll_t* cll){
    int length = len(cll);
    printN(cll,length);
}
// recursive func for freeing all nodes in cll
void freeCll_inner(node_t* head,node_t* tail){
    // base case head is equal to last node ie tail
    if (head == tail){
        free(head);
        return;
    }
    // recursive case
    freeCll_inner(head->next,tail);
    free(head);
}
// free cll and its nodes
void freeCll(cll_t* cll){
    // cll is empty then free cll
    if (cll->head == NULL){
        free(cll);
        return;
    }
    // cll is non empty
    // free all the nodes of cll
    freeCll_inner(cll->head,cll->tail);
    // then free cll
    free(cll);
}
// create new node and append to last node and make it circular
void appendCll(cll_t* cll, int data){
    // allocate space for new node
    node_t* new = malloc(sizeof(node_t));
    new->data = data;
    // when cll is empty
    if (cll->head == NULL){
        // assign new node to head and tail
        cll->head = new;
        cll->tail = new;
        // connect head to tail and tail to head
        cll->head->next = cll->tail;
        cll->tail = cll->head;
        return;
    }
    // when cll is non empty
    // make new node next point to head
    new->next = cll->head;
    // make tail's next point to new node
    cll->tail->next = new;
    // update the tail of cll
    cll->tail = new;
}
void insertHeadCll(cll_t* cll,int data){
    // allocate space for new node
    node_t* new = malloc(sizeof(node_t));
    new->data = data;

    // cll is empty
    if (cll->head == NULL){
        // point new's next to itself
        new->next = new;
        // assign new node to head and tail
        cll->head = new;
        cll->tail = new;
        return;
    }
    // point new node's next to current head
    new->next = cll->head;
    // point tail's next to new node
    cll->tail->next = new;
    // make new node the head
    cll->head = new;
}
void insertPosCll(cll_t* cll,int pos,int data){
    // insert at pos 1
    if (pos == 1){
        insertHeadCll(cll,data);
        return;
    }
    int length = len(cll);
    // append to circular list
    if (pos == length + 1){
        appendCll(cll,data);
        return;
    }
    if (pos > length + 1){
        puts("invalid position");
        return;
    }
    // inserting at position from 2 to length of cll
    node_t *trav, *trav2;
    trav = cll->head;
    // traverse trav to 1 position before pos
    for (int i = 1; i < pos-1;i++, trav = trav->next);
    // traverse trav2 to exactly at pos
    trav2 = trav->next;
    
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = trav2;
    trav->next = new;
}
void deleteHeadCll(cll_t* cll){
    // cll is empty - nothing to delete
    if (cll->head == NULL) return;
    // cll has one node only
    if (cll->head == cll->tail){
        free(cll->head);
        cll->head = NULL;
        cll->tail = NULL;
        return;
    }
    // more than one node
    // address of to be deleted node
    node_t *deleted = cll->head;
    cll->tail->next = deleted->next;
    cll->head = deleted->next;
    free(deleted);
}
void deleteTailCll(cll_t* cll){
    // cll is empty - nothing to delete
    if (cll->head == NULL) return;
    // cll has one node only
    if (cll->head == cll->tail){
        free(cll->tail);
        cll->tail = NULL;
        cll->head = NULL;
        return;
    }
    // more than one node
    // address of new tail node ie one node previous to tail
    node_t *newTail = cll->head;
    while (newTail->next != cll->tail) newTail = newTail->next;
    // point new tail's next to head
    newTail->next = cll->head;
    // delete current tail
    free(cll->tail);
    cll->tail = newTail;
}
// for deleting at any pos
void deletePosCll(cll_t* cll,int pos){
    // delete from pos 1 ie head
    if (pos == 1){
        deleteHeadCll(cll);
        return;
    }
    int length = len(cll);
    // delete from last node
    if (pos == length){
        deleteTailCll(cll);
        return;
    }
    // invalid pos
    if (pos > length){
        puts("invalid position");
        return;
    }
    // delete from pos 2 to length of cll
    node_t *trav, *deleted;
    trav = cll->head;
    // traverse to one node before pos
    for (int i = 1; i < pos-1; i++, trav = trav->next);

    deleted = trav->next;
    // point node at pos -1 's next to node at pos +1
    trav->next = deleted->next;
    free(deleted);
}
int main(){
    cll_t* cll = createCll();
    // printCll(cll);
    for (int i = 1; i < 10; i++) appendCll(cll,i);
    printCll(cll);
    deletePosCll(cll,3);
    printN(cll,14);

    freeCll(cll);
    return 0;
}