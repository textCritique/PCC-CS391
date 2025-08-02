#include <stdio.h>
#include "a4_stack_struct2.h"

int fact(int n){
    int product = 1;
    while(peek() != 1){
        push(n);
        n--;
    }
    while(peek() != -1){
        product *= pop();
    }
    return product;
}
int main(){
    int n = 5;
    printf("%d",fact(n));
    return 0;
}