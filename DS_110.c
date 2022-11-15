#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

char infixExpression[100];
char postfixExpression[100];
int length = 0;

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

int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isOperator(char ch){
    return (ch == '+' || ch <= '*') || (ch == '-' || ch == '/');
}

int validateInfixExpression(){
    int operand = 0;
    int operator = 0;
    int paranthesis = 0;

    for (int k = 0; k < length; k++){
        if(infixExpression[k] != '(' && infixExpression[k] != ')'){
            if(isOperand(infixExpression[k])){
                operand++;
                operator = 0;
                if(operand== 2){
                    return 0;
                }
            } else {
                operator++;
                operand = 0;
                if(operator == 2){
                    return 0;
                }
            }
        }
    }
    
    operand = 0;
    operator = 0;

    for (int k = 0; k < length; k++){
        if(infixExpression[k] != '(' && infixExpression[k] != ')'){
            if(isOperand(infixExpression[k])) operand++;
            else operator++;
        }
    }

    if(operator != operand-1) return 0;
    
    for (int k = 0; k < length; k++){
        if(infixExpression[k] == '('){
            if(isOperator(infixExpression[k+1])) return 0; 
            paranthesis++;
        }
        if(infixExpression[k] == ')'){ 
            paranthesis--;
            if(paranthesis < 0) return 0;
            if(isOperator(infixExpression[k-1])) return 0;
        }
    }

    if(paranthesis != 0) return 0;
    
    return 1;
}

int precedence(char ch){
    switch (ch) {
    case '+':
    case '-':
        return 1;
  
    case '*':
    case '/':
        return 2;
  
    case '^':
        return 3;
    }
    return -1;
}

void displayExpression(){
    char ch;
    int i = 0;

    if(length == 0){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | FIRST ENTER INFIX EXPRESSION.                                                |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");
    while(i<length){
        ch = postfixExpression[i];
        printf("%c", ch);
        i += 1;
    }
    printf("\n            |------------------------------------------------------------------------------|\n");
    return;
}

void infixToPostfix(){
    int i, k;
  
    struct Stack* stack = createStack(length);
  
    for (i = 0, k = -1; i < length; ++i) {

        if (isOperand(infixExpression[i]))
            postfixExpression[++k] = infixExpression[i];

        else if(infixExpression[i] == '(')
            push(stack, infixExpression[i]);

        else if(infixExpression[i] == ')'){
            while (!underflow(stack) && peek(stack) != '(') 
                postfixExpression[++k] = pop(stack);
            if (!underflow(stack) && peek(stack) != '(') return;
            else pop(stack);
        } 
        
        else{
            while (!underflow(stack) && precedence(infixExpression[i]) <= precedence(peek(stack)))
                postfixExpression[++k] = pop(stack);
            push(stack, infixExpression[i]);
        }
    }

    while (!underflow(stack))
        postfixExpression[++k] = pop(stack);
  
    displayExpression();
}

void getInput(){
    int i = 0;

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | ENTER INFIX EXPRESSION, THEN PRESS ENTER.                                    |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");
    scanf("%s",infixExpression);
    while(infixExpression[i] != '\0')
        i += 1;
    length = i;
    if(validateInfixExpression()){
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

int main(){
    int menu = 1;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This  Program  converts  Infix  notation  to  Postfix notation |\n");
    printf("            ================================================================================\n");

    while(menu){
        int menuOption;

        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Enter Infix Notation Expression.                                             |\n");
        printf("          2 | Convert Infix Notation to Postfix Notation.                                  |\n");
        printf("          3 | Display Postfix Expression.                                                  |\n");
        printf("Enter Index | ");
        scanf("%d", &menuOption);

        switch(menuOption){
            case 1: 
                getInput();
                break;
            case 2:
                infixToPostfix(); 
                break;
            case 3: 
                displayExpression();
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