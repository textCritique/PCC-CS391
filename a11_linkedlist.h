#ifndef A11_LINKEDLIST
#define A11_LINKEDLIST


//data structure for node which holds information about each link in a chain
typedef struct node{
    int data;
    struct node* next;
}node_t;

//data structure for linked list which holds address of first node.
typedef struct linkedlist{
    node_t* head;
}linkedlist_t;

linkedlist_t* CreateLinkedList();
void PrintedLinkedList(linkedlist_t* list);
int len(linkedlist_t *list);
void FreeLinkedList(linkedlist_t* list);
void AppendToLinkedList(linkedlist_t* list, int data);
void insertAtStart(linkedlist_t* list, int data);
void deleteAtEnd(linkedlist_t* list);
void deleteHead(linkedlist_t* list);
void insertPos(linkedlist_t *list, int data , int pos);
void deletePos(linkedlist_t *list, int pos);
node_t* reverse(node_t* head);
void ReverseLinkedList(linkedlist_t *list); 

#endif