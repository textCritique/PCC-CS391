
#include <stdio.h>
#include "a4_stack_struct2.h"
// node* stack;

int priority(char op){
    if (op =='(' || op ==')')
        return 4;
    else if(op =='^' )
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op =='+' || op =='-')
        return 3;
    return -1;
}
int main(){
    char infix[]= "a*(b+(c+d)*(e+f)/g)*h";
    int len = sizeof(infix)/sizeof(char);
    char postfix[len];
    int index = 0; // of postfix string where assignment will occur

    for (int i = 0; i < len; i++){
        // check if it is not a operator
        if (priority(infix[i]) == -1) {
            postfix[index++] = infix[i];
        }
        else {
            if (infix[i] == '(')
                push('(');
            else if (infix[i] == ')'){
                while(1){
                    if (peek() == '('){
                        pop();
                        break;
                    }
                    else
                        postfix[index++] = pop();
                }
            }
            else if (peek() != -1 && priority(peek()) > priority(infix[i]))
                push(infix[i]);
            else if (peek() != -1 && priority(peek()) == priority(infix[i]))
                postfix[index++] = infix[i];
            else {
                while (peek() != -1 && priority(peek()) < priority(infix[i])){
                    postfix[index++] = pop();
                }
                push(infix[i]);
            }
        }
    }
    while(peek() != -1){
        postfix[index++] = pop();
    }
    postfix[index++] = '\0';
    // final postfix expression
    printf("Postfix of %s : %s\n",infix,postfix);
    return 0;
}