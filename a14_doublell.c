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
    for (;trav != NULL;);
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
void deleteAtEnd(dll_t *dll){
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
int main(){
    dll_t* dll = createDll();
    for (int i = 0; i < 9;i++){
        appendDll(dll,i);
        printDll(dll);
    }
    for (int i =0; i< 10; i++){
        deleteAtEnd(dll);
        printDll(dll);
    }
    return 0;
}