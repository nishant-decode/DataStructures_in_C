#include <stdio.h>
#include <stdlib.h>

//defining node structure
typedef struct node{
    int power;
    int coefficient;
    struct node *next;
}Node;

//initialising nodes out of main for global scope
Node *headPE1 = NULL;
Node *headPE2 = NULL;
Node *headPAE = NULL;

void displayList(Node *head){
    Node *temp = head;

    if (temp == NULL)
    {
        printf("          ! | LINKED LIST IS EMPTY.                                                        |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf(" Expression |");
        while (temp->next != NULL){
            printf(" %dx^%d + ", temp->coefficient, temp->power);
            temp = temp->next;
        }
        printf(" %dx^%d", temp->coefficient, temp->power);
        printf("\n            |------------------------------------------------------------------------------|\n"); 
    }
    return;
}

struct node *insertNode(Node *head){
    int coefficient, power;
    printf("         -> | Enter coefficient for polynomial expression node insertion.                  |\n");
    printf("Enter Coeff | ");
    scanf("%d", &coefficient);
    printf("         -> | Enter power for polynomial expression node insertion.                        |\n");
    printf("Enter Power | ");
    scanf("%d", &power);
    
    if (head == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->coefficient = coefficient;
        temp->power = power;
        temp->next = NULL;
        head = temp;
    } else{
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->coefficient = coefficient;
        temp1->power = power;
        temp1->next = NULL;
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        if(power >= temp->coefficient){
            printf("            |------------------------------------------------------------------------------|\n");
            printf("          ! | ENTER POWER GREATER THAN LAST NODE POWER FOR CORRECT POLYNOMIAL EXPRESSION.  |\n");
            printf("            |------------------------------------------------------------------------------|\n");
            return head;
        }
        temp->next = temp1;
    }

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.                                                               |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    displayList(head);
    return head;
}

void polynomialAddition(){
    Node *temp = headPAE;
    Node *temp1 = headPE1;
    Node *temp2 = headPE2;

    if(headPE1 == NULL){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | FIRST POLYNOMIAL EXPRESSION LINKED LIST EMPTY. CREATE LIST.                  |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    if(headPE2 == NULL){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | SECOND POLYNOMIAL EXPRESSION LINKED LIST EMPTY. CREATE LIST.                 |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }

    while(temp1 != NULL && temp2 != NULL){

        int coefficient, power;

        if(temp1->power == temp2->power){
            coefficient = temp1->coefficient + temp2->coefficient;
            power = temp1->power;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if(temp1->power > temp2->power){
            coefficient = temp1->coefficient;
            power = temp1->power;
            temp1 = temp1->next;
        } else{
            coefficient = temp2->coefficient;
            power = temp2->power;
            temp2 = temp2->next;
        }

        if(temp == NULL){
            Node *temp3 = (Node *)malloc(sizeof(Node)); 
            temp3->coefficient = coefficient;
            temp3->power = power;
            temp3->next = NULL;
            headPAE = temp = temp3;
        } else{
            Node *temp3 = (Node *)malloc(sizeof(Node));
            temp3->coefficient = coefficient;
            temp3->power = power;
            temp3->next = NULL;
            temp->next = temp3;
            temp = temp->next;
        }
    }

    while(temp1 != NULL){
        if(headPAE == NULL){
            Node *temp3 = (Node *)malloc(sizeof(Node)); 
            temp3->coefficient = temp1->coefficient;
            temp3->power = temp1->power;
            temp3->next = NULL;
            headPAE = temp = temp3;
        } else{
            Node *temp3 = (Node *)malloc(sizeof(Node));
            temp3->coefficient = temp1->coefficient;
            temp3->power = temp1->power;
            temp3->next = NULL;
            temp->next = temp3;
            temp = temp->next;
        }
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        if(headPAE == NULL){
            Node *temp3 = (Node *)malloc(sizeof(Node)); 
            temp3->coefficient = temp2->coefficient;
            temp3->power = temp2->power;
            temp3->next = NULL;
            headPAE = temp = temp3;
        } else{
            Node *temp3 = (Node *)malloc(sizeof(Node));
            temp3->coefficient = temp2->coefficient;
            temp3->power = temp2->power;
            temp3->next = NULL;
            temp->next = temp3;
            temp = temp->next;
        }
        temp2 = temp2->next;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | POLYNOMIAL EXPRESSIONS ADDED.                                                |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    displayList(headPAE);
    return;
}

int main(){
    int mainMenu = 1;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This is Menu driven program to add two Polynomial Expressions. |\n");
    printf("            ================================================================================\n");

    while(mainMenu){
        int mainMenuOption;
        
        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Create First Polynomial Expression Linked List.                              |\n");
        printf("          2 | Create Second Polynomial Expression Linked List.                             |\n");
        printf("          3 | Add the two Polynomial Expressions.                                          |\n");
        printf("          4 | Display the addition of the two Expressions.                                 |\n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);

        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;
                    
                    printf("         -> | Choose a option to create the First Polynomial Expression Linked List:       |\n");
                    printf("          0 | Exit current menu.                                                           |\n");
                    printf("          1 | Insert node with Coefficient and Power.                                      |\n");
                    printf("          2 | Display Polynomial Expression.                                               |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1: {
                            headPE1 = insertNode(headPE1);
                            break;
                        }
                        case 2: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            displayList(headPE1);
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("         !! | FIRST POLYNOMIAL EXPRESSION LINKED LIST MENU EXITED.                         |\n");
                            printf("            |------------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                              |\n");
                            printf("            |------------------------------------------------------------------------------|\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;
                    
                    printf("         -> | Choose a option to create the Second Polynomial Expression Linked List:      |\n");
                    printf("          0 | Exit current menu.                                                           |\n");
                    printf("          1 | Insert node with Coefficient and Power.                                      |\n");
                    printf("          2 | Display Polynomial Expression.                                               |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1: {
                            headPE2 = insertNode(headPE2);
                            break;
                        }
                        case 2: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            displayList(headPE2);
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("         !! | SECOND POLYNOMIAL EXPRESSION LINKED LIST MENU EXITED.                        |\n");
                            printf("            |------------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                              |\n");
                            printf("            |------------------------------------------------------------------------------|\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                polynomialAddition();
                break;
            }
            case 4: {
                printf("            |------------------------------------------------------------------------------|\n");
                displayList(headPAE);
                break;
            }
            case 0: {
                mainMenu = 0;
                printf("            |------------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.                                                          |\n");
                printf("            ================================================================================\n");
                break;
            }
            default: {
                printf("            |------------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                              |\n");
                printf("            |------------------------------------------------------------------------------|\n");
                break;
            }
        }
        
    }

    return 0;
}