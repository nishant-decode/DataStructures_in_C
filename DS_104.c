#include <stdio.h>
#include <stdlib.h>

//defining node structure
typedef struct node{
    int DATA;
    struct node *prev;
    struct node *next;
}Node;

//initialising nodes out of main for global scope
Node *headD = NULL;
Node *headCD = NULL;

/* Single Linked List functions {displayListS, insertAtBeginningS, insertAtLocationS, insertAtEndS} */
void displayListD(){
    Node *temp = headD;

    if (temp == NULL)
    {
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf("       List |");
        while (temp != NULL){
            printf(" %d |", temp->DATA);
            temp = temp->next;
        }

        printf("\n            |-----------------------------------------------------------------------------|\n"); 
    }
    return;
}

void insertAtBeginningD(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headD == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        temp->prev = NULL;
        headD = temp;
    } else{
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = headD;
        temp->prev = NULL;
        headD = temp;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void insertAtEndD(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headD == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        temp->prev = NULL;
        headD = temp;
    } else{
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp1->next = NULL;
        Node *temp = headD;
        while(temp->next!=NULL)
            temp = temp->next;
        
        temp->next = temp1;
        temp1->prev = temp;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void insertAtLocationD(){
    
    int key;
    printf("         -> | Enter node data to link the node after. \n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }

    Node *temp = headD;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while((temp->DATA)!=key){
        if(temp->next == NULL){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        insertAtEndD();
        return;
    } else{
        int val;
        printf("         -> | Enter data for node insertion. \n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node *temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
        temp1->prev = temp;
        temp2->prev = temp1;
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

/* Circular Linked List Functions {displayListC, insertAtBeginningC, insertAtLocationC, insertAtEndC} */
void displayListCD(){
    Node *temp = headCD;

    if (temp == NULL)
    {
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf("       List |");
        do{
            printf(" %d |",temp->DATA);
            temp = temp->next;
        }while(headCD!=temp);
        printf("\n            |-----------------------------------------------------------------------------|\n");
    }
    return;
}

void insertAtBeginningCD(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headCD == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = temp;
        temp->prev = temp;
        headCD = temp;
    } else{
        Node *temp = headCD;
        while((temp->next->DATA)!=headCD->DATA){
            temp = temp->next;
        }
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = headCD;
        headCD->prev = temp1;
        temp1->prev = temp;
        headCD = temp1;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void insertAtEndCD(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if(headCD == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = temp;
        temp->prev = temp;
        headCD = temp;
    } else{
        Node *temp = headCD;
        while((temp->next->DATA)!=headCD->DATA)
            temp = temp->next;
        
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = headCD;
        temp1->prev = temp;
        headCD->prev = temp1;
    }
    
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void insertAtLocationCD(){
    int key;
    printf("         -> | Enter node data to link the node after. \n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headCD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    Node *temp = headCD;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while(temp->DATA != key){
        temp = temp->next;
        if(temp == headCD){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
    }
    if(temp->next == headCD){
        insertAtEndCD();
        return;
    }
    else{
        int val;
        printf("         -> | Enter data for node insertion. \n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node* temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
        temp1->prev = temp;
        headCD->prev = temp1;
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

int main(){
    int mainMenu = 1;
    
    printf("            ===============================================================================\n");
    printf("            | Welcome User! This is a Menu driven program to insert nodes in Linked Lists |\n");
    printf("            ===============================================================================\n");

    while(mainMenu){
        int mainMenuOption;
        
        printf("         -> | Choose one of the following options: \n");
        printf("          0 | Exit current menu. \n");
        printf("          1 | Double Linked List. \n");
        printf("          2 | Circular Doubly Linked List. \n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);
        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Insert node in a Double Linked List: \n");
                    printf("          0 | Exit current menu. \n");
                    printf("          1 | Insert node at Beginning. \n");
                    printf("          2 | Insert node at Specified Location. \n");
                    printf("          3 | Insert node at End. \n");
                    printf("          4 | Display Single Linked List. \n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1: {
                            insertAtBeginningD();
                            break;
                        }
                        case 2: {
                            insertAtLocationD();
                            break;
                        }
                        case 3: {
                            insertAtEndD();
                            break;
                        }
                        case 4: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            displayListD();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | DOUBLE LINKED LIST MENU EXITED.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
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

                    printf("         -> | Choose a option to Insert node in a Circular Doubly Linked List: \n");
                    printf("          0 | Exit current menu. \n");
                    printf("          1 | Insert node at Beginning. \n");
                    printf("          2 | Insert node at specified Location. \n");
                    printf("          3 | Insert node at End. \n");
                    printf("          4 | Display Circular Linked List. \n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1: {
                            insertAtBeginningCD();
                            break;
                        }
                        case 2: {
                            insertAtLocationCD();
                            break;
                        }
                        case 3: {
                            insertAtEndCD();
                            break;
                        }
                        case 4: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            displayListCD();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | CIRCULAR DOUBLY LINKED LIST MENU EXITED.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 0: {
                mainMenu = 0;
                printf("            |-----------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.\n");
                printf("            ===============================================================================\n");
                break;
            }
            default: {
                printf("            |-----------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.\n");
                printf("            |-----------------------------------------------------------------------------|\n");
                break;
            }
        }
        
    }

    return 0;
}