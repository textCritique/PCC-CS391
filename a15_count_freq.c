#include "a14_doublell.h"
#include <stdio.h>

// counts the occurence of the data - recursive function
int count(node_t * t,int data){
    if (t == NULL)
        return 0;
    else if (t->data != data) return count(t->next,data);
    else return 1+count(t->next,data);
}
// wrapper function for dll
int frequency(dll_t *dll, int data){ return count(dll->head,data);}

int main(){
    dll_t *dll = createDll();
    int data = 5;
    appendDll(dll,1),appendDll(dll,3), appendDll(dll,1), appendDll(dll,1);
    printf("Data = %d occurs %d times\n",data,frequency(dll,data));
}