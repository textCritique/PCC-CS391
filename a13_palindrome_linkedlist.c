#include "a11_linkedlist.h"
#include <stdio.h>

node_t* access(linkedlist_t *l,int pos){
    node_t *trav = l->head;
    for (int i= 0;i < pos; i++, trav = trav->next);
    return trav;
}
int ispalindrome(linkedlist_t* l){
    int n = len(l);
    node_t *front, *rear;
    for (int i = 0; i < n/2; i ++){
        front = access(l,i), rear = access(l,n-i-1);
        if ( !(front->data == rear->data)){
            return 0;
        } 
    }
    return 1;
}

int main(){
    linkedlist_t * l = CreateLinkedList();
    AppendToLinkedList(l,1),AppendToLinkedList(l,2), AppendToLinkedList(l,2),AppendToLinkedList(l,1);
    PrintedLinkedList(l);
    if (ispalindrome(l))
        printf("Palindrome");
    else
        printf("Not palindrome");
    return 0;
}