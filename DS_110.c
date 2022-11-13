#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

char infixExpression[100];
char postfixExpression[100];
int length = 0;;

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
    int i = length;

    if(length == 0){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | FIRST ENTER INFIX EXPRESSION.                                                |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");
    while(i){
        ch = postfixExpression[length - i];
        printf("%c", ch);
        i -= 1;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    return;
}

void infixToPostfix(){
    int i, k;
  
    struct Stack* stack = createStack(length);
  
    for (i = 0, k = -1; infixExpression[i]; ++i) {

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
    char ch;

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | ENTER CHARACTERS AND ADD 'Q' TO STOP, THEN PRESS ENTER.                      |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    printf(" Expression | ");
    scanf("%c", &ch);
    while(ch != 'Q'){
        infixExpression[i] = ch;
        scanf("%c", &ch);
        i += 1;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | INPUT EXPRESSION TAKEN.                                                      |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    length = i;
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