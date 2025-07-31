// stack implemented through linked list
// top of the stack is the last node of the linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node* stack = NULL;

int push(int item){
    node* temp = malloc(sizeof(node));
    if (!temp){
        return -1;
    }
    temp->data = item;
    temp->next = NULL;
    node* trav = stack;
    if (trav == NULL){
        stack = temp;
        return 0;
    }
    while(trav -> next != NULL){
        trav = trav->next;
    }
    trav->next = temp;
    return 0;
}
int pop(){
    node* trav = stack;
    if (trav == NULL)
        return -1;
    if (trav -> next == NULL){
        int popped = trav->data;
        free(trav);
        trav = NULL;
        return popped;
    }
    while(trav->next->next != NULL){
        trav = trav->next;
    }
    int popped = trav->next->data;
    free(trav->next);
    trav->next = NULL;
    return popped;
}
int peek(){
    node* trav = stack;
    if (trav == NULL)
        return -1;
    while (trav->next != NULL)
    {
        trav = trav ->next;
    }
    return trav->data;
}

void display(node* head){
    if (head == NULL){
        printf("\n");
    }
    else{
        display(head->next);
        printf("|______%3d____|\n",head->data);
    }
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
    printf("%d",peek());
    display(stack);
    return 0;
}