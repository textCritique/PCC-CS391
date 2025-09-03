#include "a14_doublell.h"
#include <stdio.h>

// itertive function to check for palindrome
int palindrome(dll_t *dll){
    node_t *forward = dll->head;
    node_t *backward = dll->tail;
    for (int i = 0; i < len(dll); i++,forward = forward->next, backward = backward->prev)
        if (forward->data != backward->data) return 0;
    return 1;
}

int main(){
    dll_t *dll = createDll();
    appendDll(dll,1),appendDll(dll,3), appendDll(dll,1), appendDll(dll,1);
    if (palindrome(dll))
        printf("Palindrome\n");
    else 
        printf("Not palindrome\n");
}