#include <stdio.h>
#include <stdlib.h>
 
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

int length = 0;
char postfixExpression[100];

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int underflow(struct Stack* stack){
    return stack->top == -1;
}
  
char peek(struct Stack* stack){
    return stack->array[stack->top];
}
  
char pop(struct Stack* stack){
    if (!underflow(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}

void getInput(){
    int i = 0;
    char ch;

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | ENTER CHARACTERS AND ADD 'Q' TO STOP, THEN PRESS ENTER.                      |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");

    scanf("%c", &ch);
    while(ch != 'Q'){
        postfixExpression[i] = ch;
        scanf("%c", &ch);
        i += 1;
    }

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | INPUT EXPRESSION TAKEN.                                                      |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    length = i;
    return;
}

void evaluatePostfixExpression(){
    int result;
    struct Stack* stack = createStack(length);

    for (int i = 0; postfixExpression[i]; ++i)
    {
        if (isdigit(postfixExpression[i]))
            push(stack, postfixExpression[i] - '0');
        else{
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            switch (postfixExpression[i]){
            case '+': push(stack, operand2 + operand1); break;
            case '-': push(stack, operand2 - operand1); break;
            case '*': push(stack, operand2 * operand1); break;
            case '/': push(stack, operand2/operand1); break;
            }
        }
    }

    result = pop(stack);
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Evaluation | ");
    printf("%d", result);
    printf("\n            |------------------------------------------------------------------------------|\n");

    return;
}

int main(){
    int menu = 1;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This  Program  converts  Infix  notation  to  Postfix notation |\n");
    printf("            ================================================================================\n");

    while(menu){
        int menuOption;

        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Enter Postfix Notation Expression.                                           |\n");
        printf("          2 | Evaluate Postfix Expression.                                                 |\n");
        printf("Enter Index | ");
        scanf("%d", &menuOption);

        switch(menuOption){
            case 1: 
                getInput();
                break;
            case 2:
                evaluatePostfixExpression(); 
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