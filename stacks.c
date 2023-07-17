
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

int isStackFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isStackFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = element;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int element = stack->data[stack->top];
    stack->top--;
    return element;
}

int main()
{
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    Stack stack;
    initializeStack(&stack);

    int num;
    char operation;

    while (fscanf(file, "%c %d\n", &operation, &num) == 2) {
        switch (operation) {
            case 'P':  // Push
                push(&stack, num);
                break;
            case 'O':  // Pop
                printf("Popped element: %d\n", pop(&stack));
                break;
            default:
                printf("Invalid operation: %c\n", operation);
                break;
        }
    }

    fclose(file);
    return 0;
}
