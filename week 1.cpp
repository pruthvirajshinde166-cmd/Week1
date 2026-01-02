#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isBalanced(char *exp) {
    for(int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(top == -1)
                return 0;

            char temp = pop();

            if((ch == ')' && temp != '(') ||
               (ch == '}' && temp != '{') ||
               (ch == ']' && temp != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    if(isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}