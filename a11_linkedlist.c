#include <stdio.h>
#include <stdlib.h>

//data structure for node which holds information about each link in a chain
typedef struct node{
    int data;
    struct node* next;
}node_t;

//data structure for linked list which holds address of first node.
typedef struct linkedlist{
    node_t* head;
}linkedlist_t;

//allocate memory for first node which is going to be head of linkedlist and return a linked list
linkedlist_t* CreateLinkedList(){
    linkedlist_t* nlist = (linkedlist_t*) malloc(sizeof(linkedlist_t));
    nlist -> head = NULL;
    return nlist;
}

void PrintedLinkedList(linkedlist_t* list){
    node_t* iter = list-> head;
    while(iter != NULL){
        printf("%d  ",iter-> data);
        iter = iter-> next;
    }
    puts("");
}

//Recursive definition of FreeLinkedList from head node

// void FreeLinkedList(node_t* head){
//     if (( head)-> next == NULL){
//         free( head);
//     }
//     else{
//         FreeLinkedList(( head)-> next);
//         free( head);
//     }
// }

//follow every links and delete all nodes
void FreeLinkedList(linkedlist_t* list){
    //current - node we want to delete
    node_t* current = list-> head;
    if(current == NULL){
        free(list);
        return; // no node to free 
    }

    //next - node next to current node
    node_t* next = current-> next;
    while(current != NULL){
        free(current);
        current = next;
        if (current != NULL){
            next = current -> next;
        }
    }
    free(list);

}

//create a new node_t and add it to last node of linkedlist_t
void AppendToLinkedList(linkedlist_t* list, int data){
    //allocate memory for new node
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new -> data = data;
    new -> next = NULL;

    //check if list is empty, i.e., head is null
    if (list->head == NULL){
        //assign it to head
        list-> head = new;
    }
    else{
        //find the last node and assign new node to next field of it
        node_t * iter = list-> head; //temporary iterator node for traversing linkedlist
        while (iter-> next != NULL){
            iter = iter-> next;
        }
        iter-> next = new;
    }

}

void insertAtStart(linkedlist_t* list, int data){
    node_t* new = malloc(sizeof(node_t));
    new->data = data;
    new->next = NULL;
    if (list->head == NULL)
        list->head = new;
    else{
        new->next = list->head;
        list->head = new;
    }
}
void deleteAtEnd(linkedlist_t* list){
    node_t* trav = list->head;
    if (!trav)
        return;
    if (trav->next == NULL){
        free(trav);
        trav = NULL;
    }
    node_t* trav2 = trav->next;
    while (trav2->next!= NULL){
        trav2 = trav2->next;
        trav = trav->next;
    }
    free(trav2);
    trav->next = NULL;
}
void deleteHead(linkedlist_t* list){
    node_t* deleted = list->head;
    if (!deleted)
        return;
    list->head = deleted->next;
    free(deleted);
}


// //////////////////////////////////////////////////////////////////////////
// void unitTest1(){
//     linkedlist_t* newlist = CreateLinkedList();
    
//     AppendToLinkedList(newlist, 9);
//     AppendToLinkedList(newlist, 8);
//     AppendToLinkedList(newlist, 7);
//     AppendToLinkedList(newlist, 6);
//     AppendToLinkedList(newlist, 5);
//     AppendToLinkedList(newlist, 4);

//     PrintedLinkedList(newlist);

//     FreeLinkedList(newlist);
// }

// void unitTest2(){
//     linkedlist_t* empty = CreateLinkedList();
//     PrintedLinkedList(empty);
//     FreeLinkedList(empty);
// }

// void unitTest3(){
//     linkedlist_t* single = CreateLinkedList();
//     AppendToLinkedList(single,100);
//     FreeLinkedList(single);
// }
// int main(){
    
//     unitTest1();
//     unitTest2();
//     unitTest3();
//     return 0;
// }
// //////////////////////////////////////////////////////////////////////////
int main(){
    linkedlist_t* l = CreateLinkedList();
    for(int i = 0; i < 5; i++){
        if (i%2)
            insertAtStart(l,i);
        else
            AppendToLinkedList(l,i);
        PrintedLinkedList(l);
    }
    for(int i = 0; i < 5; i++){
        if (i%2)
            deleteHead(l);
        else
            deleteAtEnd(l);
        PrintedLinkedList(l);
    }
}