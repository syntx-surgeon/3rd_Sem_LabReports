//Postfix Prefix Evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    double arr[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push to stack
void push(struct Stack* s, double value) {
    if (!isFull(s)) {
        s->arr[++s->top] = value;
    }
}

// Pop from stack
double pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return 0;
}

// Evaluate postfix expression
double evaluatePostfix(char* exp) {
    struct Stack s;
    initStack(&s);
    char* token = strtok(exp, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atof(token));
        } else {
            double op2 = pop(&s);
            double op1 = pop(&s);
            switch (token[0]) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}

// Evaluate prefix expression
double evaluatePrefix(char* exp) {
    struct Stack s;
    initStack(&s);
    int len = strlen(exp);
    char temp[MAX];
    char* tokens[MAX];
    int tokenCount = 0;
    
    // Tokenize the expression
    strcpy(temp, exp);
    char* token = strtok(temp, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }
    
    // Process tokens from right to left
    for (int i = tokenCount - 1; i >= 0; i--) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            push(&s, atof(tokens[i]));
        } else {
            double op1 = pop(&s);
            double op2 = pop(&s);
            switch (tokens[i][0]) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX];
    int choice;
    
    printf("Expression Evaluator\n");
    printf("1. Postfix Expression\n");
    printf("2. Prefix Expression\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Clear newline from buffer
    
    printf("Enter the expression (use spaces between elements): ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = 0; // Remove newline
    
    double result;
    if (choice == 1) {
        result = evaluatePostfix(expression);
        printf("Result of postfix expression: %.2f\n", result);
    } else if (choice == 2) {
        result = evaluatePrefix(expression);
        printf("Result of prefix expression: %.2f\n", result);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    return 0;
}