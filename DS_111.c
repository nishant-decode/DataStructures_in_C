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

int isDigit(char ch){
    return ( ch >= '0' && ch <= '9');
}

int precedence(char ch){
    switch (ch) {
    case '+':
    case '-':
        return 1;
  
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

int validPostfixExpression(){
    int operand = 0;
    int operator = 0;

    for (int k = 0; k < length; k++){
        if(isDigit(postfixExpression[k])){
            operand++;
        } else {
            if(operand < 2) return 0;
            if(precedence(postfixExpression[k]) < precedence(postfixExpression[k+1])) return 0;
            operand -= 1;
        }
    }
    
    operand = 0;

    for (int k = 0; k < length; k++){
        if(isDigit(postfixExpression[k])) operand++;
        else operator++;
    }

    if(operator != operand-1) return 0;
    
    return 1;
}

void getInput(){
    int i = 0;

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | ENTER INFIX EXPRESSION, SINGLE DIGITS AND OPERATORS ONLY, THEN PRESS ENTER.  |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");
    scanf("%s",postfixExpression);
    while(postfixExpression[i] != '\0')
        i += 1;
    length = i;
    if(validPostfixExpression()){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | INPUT EXPRESSION TAKEN.                                                      |\n");
        printf("            |------------------------------------------------------------------------------|\n"); 
    } else{
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | ENTER A VALID EXPRESSION.                                                    |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        length = 0;
    }
    return;
}

void evaluatePostfixExpression(){
    int result;
    struct Stack* stack = createStack(length);

    for (int i = 0; postfixExpression[i]; ++i)
    {
        if (isDigit(postfixExpression[i]))
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
    printf("%d\n", result);
    printf("            |------------------------------------------------------------------------------|\n");

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