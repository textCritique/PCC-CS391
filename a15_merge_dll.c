#include "a14_doublell.h"
#include <stdio.h>

// merge the two dll into single dll by appending second dll to first one
void mergeDll(dll_t *dll, dll_t *dll2){
    dll->tail->next = dll2->head;
    dll2->head->prev = dll->tail;
}

int main(){
    dll_t *dll = createDll();
    for(int i = 0; i <5; i++) appendDll(dll,i);

    dll_t *dll2 = createDll();
    for(int i = 5; i <10; i++) appendDll(dll,i);

    puts("merged dll ");
    mergeDll(dll,dll2);

    printDll(dll);
    puts("in reverse");
    // printDllp(dll);
    return 0;
}