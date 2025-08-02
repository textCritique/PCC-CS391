// do not write this one 
// work in progress
#include <stdio.h>
#include "a4_stack_struct2.h"
// node* stack;

int priority(char op){
    if (op =='(' || op ==')')
        return 4;
    else if(op =='^' )
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op =='+' || op =='-')
        return 1;
    return -1;
}
int main(){
    char infix[]="a+b*c-(d/e^f)";
    int len = sizeof(infix)/sizeof(char);
    char postfix[len];
    int counter = 0;
    int flag;
    for(int i = 0; i <len; i++){
        flag =1;
        if(priority(infix[i]) == -1)
            postfix[counter++] = infix[i];
        while(peek() != -1 && priority(infix[i]) != -1 && priority(infix[i]) != 4 && priority(infix[i]) <= priority((char)peek())){
            postfix[counter++]=(char)pop();
            flag = 0;
        }
        if (flag)
            push(infix[i]);
        if(infix[i]=='(')
            push('(');
        while (infix[i] == ')'){
            if((char)peek() == '('){
                pop();
                break;
            }
            postfix[counter++] = (char)pop();
        }
    }
    while(peek()!=-1)
        postfix[counter++] = (char) pop();
    for(int i = 0; i<len; i++)
        printf("%c",postfix[i]);
    return 0;
}