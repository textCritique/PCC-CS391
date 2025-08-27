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
// length of the ll
int len(linkedlist_t *list){
    int length = 0;
    node_t *trav = list->head;
    while (trav != NULL){
        trav = trav->next;
        length++;
    }
    return length;
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
// insert at the first pos
void insertAtStart(linkedlist_t* list, int data){
    node_t* new = malloc(sizeof(node_t));
    new->data = data;
    new->next = NULL;
    // if ll is empty
    if (list->head == NULL)
        list->head = new;
    else{
        new->next = list->head;
        list->head = new;
    }
}
// deletes the node from the end of ll
void deleteAtEnd(linkedlist_t* list){
    node_t* trav = list->head;
    // ll is already empty - nothing to delete
    if (!trav)
        return;
    // ll has only one element
    if (trav->next == NULL){
        free(trav);
        list->head = NULL; // was doing trav = NULL - cause of bug because list->head is still pointing at freed address
        return;
    }
    // more than 1 node in ll
    node_t* trav2 = trav->next;
    while (trav2->next!= NULL){
        trav2 = trav2->next;
        trav = trav->next;
    }
    free(trav2);
    trav->next = NULL;
}
// delete the first node of ll
void deleteHead(linkedlist_t* list){
    node_t* deleted = list->head;
    if (!deleted)
        return;
    list->head = deleted->next;
    free(deleted);
}
// for inserting at a given position if possible - valid pos 1 to length of linked list
void insertPos(linkedlist_t *list, int data , int pos){
    // insert at first pos
    if (pos == 1){
        insertAtStart(list,data);
        return;
    }
    int length = len(list);
    // append to the list
    if (pos == length +1){
        AppendToLinkedList(list,data);
        return;
    }
    if (pos > length+1){
        puts("not a valid position");
        return;
    }
    // inserting at position from 2 to length of ll
    node_t *trav, *trav2;
    trav = list ->head;
    // traverse trav to 1 position before pos
    for (int i = 1; i < pos-1; i++, trav = trav->next);
    trav2 = trav->next;

    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = trav2;
    trav->next =new;
}
// for deleting at a given pos
void deletePos(linkedlist_t *list, int pos){
    // delete the first node
    if (pos == 1){
        deleteHead(list);
        return;
    }
    int length = len(list);
    // delete the last node
    if (pos == length){
        deleteAtEnd(list);
        return;
    }
    // for deleting node between 2 to length of ll -1
    node_t *trav = list->head;
    for (int i = 1; i < pos -1; i++, trav = trav->next);
    node_t *deleted = trav->next;
    trav->next = deleted->next;
    free(deleted);
}
// recursive function to reverse a list given head node
// returns head node of reversed list
node_t* reverse(node_t* head){
    // base case - there is only one node then list is reversed
    if (head != NULL && head->next == NULL)
        return head;
    // two nodes
    else if (head->next != NULL && head->next->next == NULL){
        // change the data of the head node first so make a temp copy
        int temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;
        return head;
    }
    // recursive case - reverse the node after the head and connect reversed node to the last of node
    node_t *trav = reverse(head->next);
    node_t *newhead = trav;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = head;
    head->next = NULL;
    return newhead;
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
    for(int i = 1; i < 11; i++){
        AppendToLinkedList(l,i);
    }
    PrintedLinkedList(l);
    l->head = reverse(l->head);
    PrintedLinkedList(l);
    FreeLinkedList(l);
    // for(int i = 0; i < 5; i++){
    //     if (i%2)
    //         deleteHead(l);
    //     else
    //         deleteAtEnd(l);
    //     PrintedLinkedList(l);
    // }
}