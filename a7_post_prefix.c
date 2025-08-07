#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
int top = -1;
char* stack[MAX];

char* peek(){
    if (top > -1 && top < MAX)
        return stack[top];
    return NULL;
}
char* pop(){
    if (top > -1 && top < MAX)
        return stack[top--];
    return NULL;
}
int push(char* str){
    if (top + 1 < MAX){
        stack[++top] = str;
        return 1;
    }
    return 0;
}

char* concat(char* first, char* second, char* third){
    int flen = strlen(first);
    int slen = strlen(second);
    int tlen = strlen(third);
    char* concatenated = malloc(sizeof(flen+slen+tlen+1));
    if (!concatenated){
        perror("malloc");
        return NULL;
    }
    for (int i = 0; i < flen+slen+tlen; i++){
        if (i < flen){
            concatenated[i] = first[i];
        }
        else if (i < flen + slen){
            concatenated[i] = second[i-flen];
        }
        else {
            concatenated[i] = third[i-flen-slen];
        }
    }
    concatenated[flen+slen+tlen] = '\0';
    return concatenated;
}
int main(){
    char postfix[] = "AB+C+D*E-";
    int len = strlen(postfix);
    char prefix[len];
    char* second, *first;
    for (int i = 0 ; i < len; i++){
        switch (postfix[i]){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            first = pop();
            second =pop();
            char* operator = malloc(2);
            operator[0] = postfix[i], operator[1] = '\0';
            push(concat(operator,second,first));
            break;
        default:
            char* operand = malloc(2);
            operand[0] = postfix[i], operand[1] = '\0';
            push(operand);
            break;
        }
    }
    printf("Prefix of %s: %s",postfix,peek());
    return 0;
}