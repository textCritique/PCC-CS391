#include "a11_linkedlist.h"

node_t* access(linkedlist_t *l,int pos){
    node_t *trav = l->head;
    for (int i= 0;i < pos; i++, trav = trav->next);
    return trav;
}
void sortedList(linkedlist_t* l){
    node_t* trav = l->head;
    int temp, n = len(l);
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n-i-1; k++){
            node_t *j = access(l,k), *j1 = access(l,k+1);
            if (j->data > j1->data){
                temp = j->data;
                j->data = j1->data;
                j1->data = temp;
            }
        }
    }
}

int main(){
    linkedlist_t* list = CreateLinkedList();
    for (int i = 10; i > 0; i--) AppendToLinkedList(list,i);
    PrintedLinkedList(list);
    sortedList(list);
    PrintedLinkedList(list);
}