#include "a14_doublell.h"
#include <stdio.h>

// merge the two dll into single dll by appending second dll to first one
void mergeDll(dll_t *dll, dll_t *dll2){
    // case 1: first dll is empty
    // make the head of first dll equal to head of second dll
    // and tail of first dll equal to tail of second dll
    if (dll->head == NULL && dll2->head != NULL){
        dll->head = dll2->head;
        dll->tail = dll2->tail;
        return;
    }
    // case 2: second dll is empty or both is empty
    // no need to do anything
    if ( (dll->head != NULL && dll2->head == NULL) || (dll->head == NULL && dll->head == NULL) ) return;
    // case 3: both dll is non empty
    // first point next of dll 's tail to dll2's head - forward linking done
    dll->tail->next = dll2->head;
    // point prev of node after dll's tail to dll's tail
    dll->tail->next->prev = dll->tail;
    // make dll's tail point to dll2's tail
    dll->tail = dll2->tail;
}

int main(){
    dll_t *dll = createDll();
    for(int i = 0; i <5; i++) appendDll(dll,i);

    dll_t *dll2 = createDll();
    for(int i = 5; i <10; i++) appendDll(dll2,i);

    puts("merged dll ");
    mergeDll(dll,dll2);

    printDll(dll);
    puts("in reverse");
    printDllp(dll);
    return 0;
}