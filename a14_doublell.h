#ifndef A14_DOUBLELL
#define A14_DOUBLELL


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
dll_t* createDll();

// iterating using next and printing
void printDll(dll_t* dll);

// iterating using prev and printting
void printDllp(dll_t* dll);

// length of the dll
int len(dll_t* dll);

// follow all links and delete all the nodes
void freeDll(dll_t* dll);

// create a new node and append it to head
void appendDll(dll_t * dll, int data);

// delete a node from the end
void deleteTail(dll_t *dll);

// insert at the beginning of the dll
void insertHead(dll_t* dll,int data);

// delete from the first node
void deleteHead(dll_t *dll);

// for inserting at a given position if possible - valid pos range from 1 to n+1
void insertPos(dll_t *dll, int data, int pos);

// deleting at specified pos
void deletePos(dll_t *dll,int pos);

// reverse a dll - a helper function
// returns the head node of the reversed dll
node_t* reverse(node_t* head);

// wrapper function for reverse
void ReverseDll(dll_t *list);

#endif