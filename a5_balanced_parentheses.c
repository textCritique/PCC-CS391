#include <stdio.h>
#include "a4_stack_struct2.h"
#include <string.h>

// function to check if parentheses is balanced or not
// 0 means not balanced and 1 means balanced
int is_balanced_parentheses(char* s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        switch (s[i]){
            case '[':
            case '{':
            case '(':
                push(s[i]);
                break;
            case ']':
                if (peek() == '[')
                    pop();
                else 
                    return 0;
                break;
            case '}':
                if (peek() == '{')
                    pop();
                else
                    return 0;
                break;
            case ')':
                if (peek() == '(')
                    pop();
                else
                    return 0;
                break;
        }
    }
    if (peek() == -1)
        return 1;
    else
        return 0;
}

int main(){
    char balanced[] = "()[{}()]";   // balanced parentheses
    // char unbalanced[] = "()[{}(])"; // unbalanced parentheses
    printf("%d =balanced\n",is_balanced_parentheses(balanced));
    return 0;
}