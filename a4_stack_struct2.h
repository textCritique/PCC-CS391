#ifndef A4_STACK_STRUCT2
#define A4_STACK_STRUCT2
typedef struct node{
    int data;
    struct node* next;
}node;

extern node* stack;

int push(int item);

int pop();

void display(node* stack);

int peek();
#endif