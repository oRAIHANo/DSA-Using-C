// Paranthesis Matching Problem
// If there is an opening paranthesis ( then push into the stack
// If there is a closing paranthesis ) then pop ( from the stack
// Example of a balanced expression = ((a+b) * (a-b))
// Example of an unbalanced expression = (a+b) * (a-b)) and (a * (b - a*(c)
// Condition for a balanced expression
// While popping stack should not be underflow or empty -> If it happens then expression is unbalanced
// At the end of expression stack must be empty
// Best case complexity: O(1)
// Worst case complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

#define size 100

char array[size];
int top = -1, choice;

// code to push or insert element into the stack
void Push(char value)
{
    if (top == size - 1)
    {
        printf("Stack Overflow cannot push %d\n", value);
    }
    else
    {
        top++;
        array[top] = value;
    }
}

// code to pop or delete element from the stack
char Pop()
{
    if (top == -1)
    {
        printf("Stack Underflow cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char value = array[top];
        top--;
        return value;
    }
}

// code to solve parenthesis matching problem
int Parenthesis(char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            Push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (top == -1)
            {
                return 0;
            }
            char popped = Pop();
            if ((expr[i] == ')' && popped != '(') || (expr[i] == '}' && popped != '{') || (expr[i] == ']' && popped != '['))
            {
                return 0; // Mismatched closing bracket
            }
        }
    }

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // char *expr = "((a+b) * (a-b))";
    // char *expr = "(a+b) * (a-b))";
    char *expr = "{[(a+b) * (a-b)] + (a*b)";

    if (Parenthesis(expr))
    {
        printf("Parenthesis is matching");
    }
    else
    {
        printf("Parenthesis is not matching");
    }

    return 0;
}
