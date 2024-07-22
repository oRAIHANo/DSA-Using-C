// This code is not working
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

struct stack *s, *sp;
int top = -1, value, choice;

// code to check if stack is empty
int IsEmpty()
{
    if (sp->top == -1)
    {
        return 1; // 1 means stack is empty
    }
    else
    {
        return 0; // 0 means stack is not empty
    }
}

// code to check if stack is full
int IsFull()
{
    if (sp->top == sp->size - 1)
    {
        return 1; // 1 means stack is full
    }
    else
    {
        return 0; // 0 means stack is not full
    }
}

// code to push or insert element into the stack
void Push()
{
    if (sp->top == sp->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the value that you want to push : ");
        scanf("%d", &value);
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

// code to pop or delete element from the stack
int Pop()
{
    if (IsEmpty(sp))
    {
        printf("Stack Underflow cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

// code to view element at a given position in stack
// int Peek()
// {
//     int i;
//     int arrIndex = sp->top - i + 1;
//     if (arrIndex < 0)
//     {
//         printf("Not a valid position");
//     }
//     else
//     {
//         return sp->arr[arrIndex];
//     }
// }

void Display()
{
    for (int i = sp->top; i >= 0; i--)
    {
        printf("Element %d : %d", i, sp->arr[i]);
    }
}

// code to print the top most element of the stack
int StackTop()
{
    return sp->arr[sp->top];
}

// code to print the bottom most element of the stack
int StackBottom()
{
    return sp->arr[0];
}

void main()
{
    // struct stack s: This declares a variable named s of type struct stack.
    // Here, s holds the actual structure, and memory for it is allocated directly on the stack.
    // You can access members of the structure using the dot (.) operator, like s.member.
    // struct stack s;
    // s.size = 50;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // struct stack *s: This declares a pointer variable named s of type "pointer to struct stack".
    // Here, s doesn't hold the structure itself but holds the memory address (a pointer)
    // where a struct stack type structure resides. You need to allocate memory for the structure
    // dynamically using functions like malloc() before using it, and you access members of the
    // structure using the arrow (->) operator, like s->member.
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    while (1)
    {
        printf("\nMenu\n");
        printf("Enter 1 to Push element into the stack\n");
        printf("Enter 2 to Pop element from the stack\n");
        printf("Enter 3 to Display element at top\n");
        printf("Enter 4 to Display element at bottom\n");
        printf("Enter 5 to Display all elements\n");
        printf("Enter 6 to Exit\n");

        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            StackTop();
            break;
        case 4:
            StackBottom();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("Exiting program");
            exit(0);
        default:
            printf("Choice is invalid");
            break;
        }
    }
}