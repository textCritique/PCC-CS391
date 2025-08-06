// do not write this 
// work in progress
#include <stdio.h>
#include "a4_stack_struct2.h"
#include <string.h>

int num(char c){
    return (int) (c - '0');
}


int main()
{
    char postfix[] = "142/+32*-";
    int rhs,lhs;
    int len = strlen(postfix);
    for (int i = 0; i<len; i++){
        switch(postfix[i]){
            case '+':
                rhs = pop();
                lhs = pop();
                push(lhs+rhs);
                break;
            case '-':
                rhs = pop();
                lhs = pop();
                push(lhs-rhs);
                break;
            case '*':
                rhs = pop();
                lhs = pop();
                push(lhs*rhs);
                break;
            case '/':
                rhs = pop();
                lhs = pop();
                push(lhs/rhs);
                break;
            default:
                push(num(postfix[i]));
        }
    }
    printf("%s = %d",postfix,peek());
    return 0;
}