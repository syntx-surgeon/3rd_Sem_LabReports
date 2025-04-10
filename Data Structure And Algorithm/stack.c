#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full!\n");
    }
    else
    {
        s->data[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return s->data[(s->top)--];
    }
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return s->data[s->top];
    }
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->data[i]);
        }
    }
}

int main()
{
    Stack s;
    initialize(&s);
    int choice, value;
    printf("Pogram Stack\n");
    printf("Compiled By Bhim Raj Bhandari\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = pop(&s);
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            value = peek(&s);
            if (value != -1)
            {
                printf("Top value: %d\n", value);
            }
            break;
        case 4:
            display(&s);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
