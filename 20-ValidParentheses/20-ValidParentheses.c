// Last updated: 8/4/2026, 12:26:00 PM
#include <stdbool.h>

#define MAX_SIZE 10000

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, char ch) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = ch;
    }
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // return -1 if stack is empty
}

// Main function to check if the string has valid parentheses
bool isValid(char *s) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return false; // No matching opening bracket
            }
            
            char top = pop(&stack);
            
            // Check if the top of the stack matches the closing bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    // If the stack is empty, all brackets are matched
    return isEmpty(&stack);
}
