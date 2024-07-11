#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prec(char c);
char associativity(char c);
int toPostfix(char infix[], char postfix[], int i, int top);

int main() {
    char *infix, *postfix;
    
    printf("Enter a mathematical expression:\n");
    char expression[100];
    scanf("%s", expression);

    infix = malloc(sizeof(char) * (strlen(expression) + 2)); // +2 for '(' and ')'
    infix[0] = '(';
    for (int i = 1; expression[i - 1] != '\0'; i++) {
        infix[i] = expression[i - 1];
    }
    infix[strlen(expression) + 1] = ')';
    infix[strlen(expression) + 2] = '\0';

    postfix = malloc(sizeof(char) * strlen(infix));

    toPostfix(infix, postfix, 0, -1);

    printf("Postfix Expression: %s\n", postfix);

    free(infix);
    free(postfix);

    return 0;
}

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

char associativity(char c) {
    if (c == '^') return 'R';
    return 'L'; // Default to left-associative
}

int toPostfix(char infix[], char postfix[], int i, int top) {
    if (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[++top] = infix[i];
        } else if (infix[i] == '(') {
            top = toPostfix(infix, postfix, i + 1, top);
        } else if (infix[i] == ')') {
            return top;
        } else {
            while (top != -1 && prec(postfix[top]) >= prec(infix[i]) && associativity(postfix[top]) == 'L') {
                postfix[++top] = infix[i];
                i++;
            }
            top = toPostfix(infix, postfix, i, top);
        }
        return toPostfix(infix, postfix, i + 1, top);
    }
    return top;
}
