#include <stdio.h>
#include <stdlib.h>
  
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} STACK;

STACK* createStack(unsigned capacity){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | STACK CREATED.                                                               |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    return stack;
}

int overflow(STACK* stack){
    return stack->top == stack->capacity - 1;
}
  
int underflow(STACK* stack){
    return stack->top == -1;
}

void push(STACK* stack, int item){
    if (overflow(stack)){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | STACK OVERFLOW.                                                              |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    
    stack->array[++stack->top] = item;
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | %d PUSHED TO STACK.                                                           \n", item);
    printf("            |------------------------------------------------------------------------------|\n");
    return;
}
  
void pop(STACK* stack){
    if (underflow(stack)){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | STACK UNDERFLOW.                                                             |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | %d POPED FROM STACK.                                                          \n", stack->array[stack->top--]);
    printf("            |------------------------------------------------------------------------------|\n");
    return;
}
  
int main(){

    int menu = 1;
    int stackCreated = 0;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This is a Menu driven program to implement Stacks using Arrays |\n");
    printf("            ================================================================================\n");

    while(menu){
        int menuOption;
        STACK* stack;

        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Create Stack using Arrays.                                                   |\n");
        printf("          2 | Push elements in Stack.                                                      |\n");
        printf("          3 | Pop elements from Stack.                                                     |\n");
        printf("          4 | Check status of the stack for underflow or overflow.                         |\n");
        printf("Enter Index | ");
        scanf("%d", &menuOption);

        switch(menuOption){
            case 1: 
                stack = createStack(100);
                stackCreated = 1;
                break;
            case 2: 
                printf("            |------------------------------------------------------------------------------|\n");
                if(stackCreated == 1){
                    int val;
                    printf("         -> | Enter element to push in Stack.                                              |\n");
                    printf("    Element | ");
                    scanf("%d", &val);
                    push(stack, val);
                } else{
                    printf("          ! | FIRST CREATE STACK.                                                          |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 3: 
                printf("            |------------------------------------------------------------------------------|\n");
                if(stackCreated == 1){
                    pop(stack);
                } else{
                    printf("          ! | FIRST CREATE STACK.                                                          |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 4:
                if (overflow(stack)){
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | STACK OVERFLOW.                                                              |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                } else if (underflow(stack)){
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | STACK UNDERFLOW.                                                             |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | STACK NEITHER OVERFLOW NOR UNDERFLOW.                                        |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 0:
                menu = 0;
                printf("            |------------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.                                                          |\n");
                printf("            ================================================================================\n");
                break;
            default:
                printf("            |------------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                              |\n");
                printf("            |------------------------------------------------------------------------------|\n");
                break;
        }
        
    }
    return 0;
}