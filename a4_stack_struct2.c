// stack implemented through linked list
// top of the stack is the head node of the linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* stack;

int push(int item){
    node* temp = malloc(sizeof(node));
    if (!temp){
        perror("malloc");
        return -1;
    }
    temp->data = item;
    temp ->next = NULL;
    if (stack == NULL){
        stack = temp;
        return 0;
    }
    temp->next = stack;
    stack = temp;
    return 0;
}

int pop(){
    if (stack == NULL)
        return -1;
    node* temp = stack;
    stack = stack->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void display(node* stack){
    for (node* p = stack; p != NULL; p = p->next){
        printf("|______%5d______|\n",p->data);
    }
}
int peek(){
    if(stack == NULL){
        return -1;
    }
    return stack->data;
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    push(10);
    printf("%d\n",peek());
    display(stack);
    return 0;
}