#include <stdio.h>
#include <stdlib.h>

//data structure for node which holds information about each link in a chain
typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node_t;

//data structure for doubly linked list which holds address of first node and last node
typedef struct dlinkedlist{
    node_t* head;
    node_t* tail;
}dll_t;

// allocate memory for dll_t which will store the head and tail
dll_t* createDll(){
    dll_t* dll = malloc(sizeof(dll_t));
    dll ->head = NULL;
    dll->tail = NULL;
    return dll;
}
// iterating using next and printing
void printDll(dll_t* dll){
    node_t* trav = dll->head;
    while(trav != NULL){
        printf("%d ",trav->data);
        trav = trav->next;
    }
    puts("");
}
// iterating using prev and printting
void printDllp(dll_t* dll){
    node_t* trav = dll->tail;
    while(trav != NULL){
        printf("%d ",trav->data);
        trav = trav->prev;
    }
    puts("");
}
// length of the dll
int len(dll_t* dll){
    node_t *trav = dll->head;
    int length = 0;
    for (;trav != NULL;length++, trav = trav->next);
    return length;
}
// follow all links and delete all the nodes
void freeDll(dll_t* dll){
    // current - node to delete
    node_t* current = dll->head;
    // if dll contains only one node
    if (current == NULL){
        free(dll);
        return;
    }
    // next - node next to current
    node_t *next = current->next;
    while(current != NULL){
        free(current);
        current = next;
        if (next != NULL)
            next = next->next;
    }
    free(dll);
}
// create a new node and append it to head
void appendDll(dll_t * dll, int data){
    // allocate memory for the new node
    node_t* new = malloc(sizeof(node_t));
    new->next = NULL;
    new->prev = NULL;
    new->data = data;
    // when dll is empty
    if (dll->head == NULL && dll->tail == NULL){ // checking for head is also enough
        dll->head = new;
        dll->tail = new;
        return;
    }
    // when dll has one node only
    if (dll->head == dll->tail){
        dll->head->next = new;
        new->prev = dll->head;
        dll->tail = new;
        return;
    }
    // when dll has 2 or more nodes
    dll->tail->next = new;
    new->prev = dll->tail;
    dll->tail = new;
}
// delete a node from the end
void deleteTail(dll_t *dll){
    // when already empty
    if (dll->head == NULL && dll->tail == NULL){
        printf("already empty");
        return;
    }
    // when single node
    if (dll->head == dll->tail){
        free(dll->head); //as both head and tail point to same address so freeing head frees tail too
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }
    // when two or more nodes
    node_t *deleted = dll->tail;
    dll->tail = deleted->prev;
    dll->tail->next = NULL;
    free(deleted);
}
// insert at the beginning of the dll
void insertHead(dll_t* dll,int data){
    node_t *new = malloc(sizeof(node_t));
    new->next = NULL;
    new->prev = NULL;
    new->data = data;
    // when dll is empty
    if (dll->head == NULL && dll->tail == NULL){ // checking for head is also enough
        dll->head = new;
        dll->tail = new;
        return;
    }
    // when dll contains one node only
    if (dll->head == dll->tail){
        new->next = dll->tail;
        dll->tail->prev = new;
        dll->head = new;
        return;
    }
    // when dll has two or more elements
    new->next = dll->head;
    dll->head->prev = new;
    dll->head = new;
}
// delete from the first node
void deleteHead(dll_t *dll){
    node_t *deleted = dll->head;
    if (!deleted){ // check if dll is empty
        printf("already empty\n");
        return;
    }
    // when only one node is available
    if (deleted->next == NULL){
        free(deleted);
        dll->head = NULL;
        dll->tail = NULL;
        return;
    }
    // when two or more nodes are available
    deleted->next->prev = NULL;
    dll->head = deleted->next;
    free(deleted);
}
// for inserting at a given position if possible - valid pos range from 1 to n+1
void insertPos(dll_t *dll, int data, int pos){
    // insert at first pos
    if (pos == 1){
        insertHead(dll,data);
        return;
    }
    int length = len (dll);
    // append to the dll
    if (pos == length+1){
        appendDll(dll,data);
        return;
    }
    // check for invalid pos
    if (pos > length + 1){
        printf("not a valid position");
        return;
    }
    // inserting at pos from 2 to length
    node_t *beforePos, *atPos;
    beforePos = dll->head;
    for (int i = 1; i < pos-1; i++,beforePos = beforePos->next);
    atPos = beforePos->next;

    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = atPos;
    atPos->prev = new;
    beforePos->next = new;
    new->prev = beforePos;
}
// deleting at specified pos
void deletePos(dll_t *dll,int pos){
    // delete the first node
    if (pos == 1){
        deleteHead(dll);
        return;
    }
    int length = len(dll);
    // delete the last node
    if (pos == length){
        deleteTail(dll);
        return;
    }
    // check for invalid pos
    if (pos > length){
        puts("not a valid position");
        return;
    }
    // for deleting node between 2 to length of dll -1
    node_t *deleted, *beforePos;
    beforePos = dll->head;
    for (int i = 1; i < pos-1; i++, beforePos = beforePos->next );
    deleted = beforePos->next;
    beforePos->next = deleted->next;
    deleted->next->prev = beforePos;
    free(deleted);
}
// reverse a dll - a helper function
// returns the head node of the reversed dll
node_t* reverse(node_t* head){
    // base case - there is only one node then list is reversed
    if (head != NULL && head->next == NULL)
        return head;
    // two nodes
    else if (head->next != NULL && head->next->next == NULL){
        // reverse the two nodes
        node_t *tail = head->next;
        tail->next = head;
        head->prev = tail;
        head->next = NULL;
        tail->prev = NULL;
        // tail becomes new head
        return tail;
    }
    // recursive case - reverse the node after the head and connect reversed node to the last of node
    node_t *newhead = reverse(head->next);
    node_t *trav = newhead;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = head;
    head->prev = trav;
    head->next = NULL;
    return newhead;
}
// wrapper function for reverse
void ReverseDll(dll_t *list){
    if (list->head == NULL)
        return;
    list->head = reverse(list->head);
    node_t *trav = list->head;
    // assign new tail to dll
    for (;trav->next != NULL; trav = trav->next);
    list->tail = trav;
}
int main(){
    dll_t* dll = createDll();
    int n = 6;
    
    for (int i = 0; i < n;i++){
        appendDll(dll,i);
    }
    puts("Print the dll by following head node");
    printDll(dll);
    ReverseDll(dll);
    puts("Print reversed list");
    printDll(dll);
    deleteHead(dll);
    puts("After deleting head");
    printDll(dll);
    insertHead(dll,0);
    puts("Inserting from the head");
    printDll(dll);
    deleteTail(dll);
    puts("Deleting from the end");
    printDll(dll);
    insertPos(dll,100,3);
    puts("Inserting 100 to 3rd position");
    printDll(dll);
    deletePos(dll,3);
    puts("Deleting from the 3rd pos");
    printDll(dll);
    puts("Printing by following the tail");
    printDllp(dll);
    return 0;
}