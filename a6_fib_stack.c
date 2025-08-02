#include <stdio.h>
#include "a4_stack_struct2.h"

int fib(int n){
    int sum = 0,popped;
    push(n);
    while (peek() != -1){
        display(stack);
        puts("");
        popped = pop();
        if (popped == 1 || popped == 0)
            sum++;
        else {
            push(popped-1);
            push(popped-2);
        }
    }
    return sum;
}
int main(){
    int n = 3;
    printf("%d nth is %d",n,fib(n));
    return 0;
}