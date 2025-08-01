#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* head = NULL;
node* tail = NULL;

int append(int item){
    node* temp = malloc(sizeof(node));
    if (!temp){
        perror("malloc");
        return 1;
    }
    temp->data = item;
    if (!head){
        head = temp;
        head->next = NULL;
        head->prev = NULL;
    }
    if (!tail){
        tail = temp;
        tail-> next = NULL;
        tail->prev = NULL;
    }
    if (head == tail){
        tail = temp;
        tail ->next = NULL;
        tail ->prev = head;
    }
    else
}
int main(){
    return 0;
}