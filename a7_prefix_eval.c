#include <stdio.h>
#include <stdlib.h>
#include "a4_stack_struct2.h"
#include <math.h>
#include <string.h>
#define MAX 10000
#define NO_DIGITS 9

char prefix[MAX] = "+,+,2,6,+,-,13,2,4";
// returns full number as int
int num(int* index){
    int counter = 0;
    char num[NO_DIGITS];
    while (prefix[*(index)] != ','){
        num[counter++] = prefix[*(index)];
        *index = *index -1;
    }
    // -1 return value means max no of digit is exceeded
    if (counter > NO_DIGITS) return -1;
    char temp[counter];
    for (int i= 0; i < counter;i++) 
        temp[i] = num[counter-i-1];
    return atoi(temp);
}
int main(){
    int lhs,rhs;
    // iterating from right to left in prefix for eval
    for (int i = strlen(prefix)-1; i >= 0 ; i--){
        switch (prefix[i])
        {
        case '^':
            lhs = pop(), rhs = pop();
            push((int)pow(lhs,rhs));
            break;
        case '*':
            lhs = pop(), rhs = pop();
            push(lhs * rhs);
            break;
        case '/':
            lhs = pop(), rhs = pop();
            push(lhs / rhs);
            break;
        case '%':
            lhs = pop(), rhs = pop();
            push(lhs % rhs);
            break;
        case '+':
            lhs = pop(), rhs = pop();
            push(lhs + rhs);
            break;
        case '-':
            lhs = pop(), rhs = pop();
            push(lhs - rhs);
            break;
        case ',':
            continue;
        default:
            // operand - we convert it to no and push onto the stack
            push(num(&i));
            break;
        }
    }
    printf("%s = %d",prefix,peek());
    return 0;
}