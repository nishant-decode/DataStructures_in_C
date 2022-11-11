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

/* Single Linked List functions {displayListS, insertAtBeginningS, insertAtLocationS, insertAtEndS, deleteAtBeginningS, deleteAtEndS, deleteAtLocationS} */
void displayListD(){
    Node *temp = headD;

    if (temp == NULL)
    {
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.                                                |\n");
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
    printf("         -> | Enter data for node insertion.                                              |\n");
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
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void insertAtEndD(){
    int val;
    
    printf("         -> | Enter data for node insertion.                                              |\n");
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
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void insertAtLocationD(){
    
    int key;
    printf("         -> | Enter node data to link the node after.                                     |\n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.                                                |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }

    Node *temp = headD;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while((temp->DATA)!=key){
        if(temp->next == NULL){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.                                                |\n");
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
        printf("         -> | Enter data for node insertion.                                              |\n");
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
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void deleteAtBeginningD(){
    if(headD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.                                                |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    } else{
        Node *temp = headD;
        headD = headD->next;
        temp->next = NULL;
        free(temp);
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE DELETED.                                                               |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void deleteAtEndD(){
    Node *temp;
    Node *temp1;

    if(headD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.                                                |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    } else if(headD->next == NULL && headD->prev == NULL){
        temp = headD;
        headD = NULL;
        free(temp);
    } else{
        temp = headD;

        while(temp->next->next!=NULL)
            temp = temp->next;
        
        temp1 = temp;
        temp = temp->next;
        temp1->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE DELETED.                                                               |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListD();
    return;
}

void deleteAtLocationD(){
    Node *temp = headD;
    Node *temp1, *temp2;

    if(headD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | DOUBLE LINKED LIST IS EMPTY.                                                |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }

    int key;
    printf("         -> | Enter node data to delete the node.                                         |\n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    while(temp->DATA!=key){
        temp1 = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.                                                 |\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
    }
    if(temp == headD){
        if(temp->next == NULL){
            headD = NULL;
            free(temp);
        } else{
            headD = temp->next;
            headD->prev = NULL;
            temp->next = NULL;
            free(temp);
        }
    } else{
        temp2 = temp->next;
        temp2->prev = temp1;
        temp1->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    
    displayListD();
    return;
}

/* Circular Linked List Functions {displayListC, insertAtBeginningC, insertAtLocationC, insertAtEndC, deleteAtBeginningC, deleteAtEndC, deleteAtLocationC} */
void displayListCD(){
    Node *temp = headCD;

    if (temp == NULL)
    {
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.                                       |\n");
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
    printf("         -> | Enter data for node insertion.                                              |\n");
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
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void insertAtEndCD(){
    int val;
    printf("         -> | Enter data for node insertion.                                              |\n");
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
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void insertAtLocationCD(){
    int key;
    printf("         -> | Enter node data to link the node.                                           |\n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headCD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.                                       |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    Node *temp = headCD;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while(temp->DATA != key){
        temp = temp->next;
        if(temp == headCD){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.                                                |\n");
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
        printf("         -> | Enter data for node insertion.                                              |\n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node *temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
        temp1->prev = temp;
        headCD->prev = temp1;
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.                                                              |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void deleteAtBeginningCD(){
    if(headCD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.                                       |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    } if(headCD->next == headCD){
        headCD = NULL;
        free(headCD);
    }
    else{
        Node *temp = headCD;
        Node *temp1 = headCD;

        while(temp->next!=headCD)
            temp = temp->next;

        headCD = headCD->next;
        temp->next = headCD;
        temp->prev = NULL;
        temp1->next = NULL;
        free(temp1);
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE DELETED.                                                               |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void deleteAtEndCD(){
    Node *temp;
    Node *temp1;

    if(headCD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.                                       |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    } else if(headCD->next == headCD){
        temp = headCD;
        headCD = NULL;
        free(temp);
    } else{
        temp = headCD;
        while(temp->next!=headCD){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        headCD->prev = temp1;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE DELETED.                                                               |\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListCD();
    return;
}

void deleteAtLocationCD(){    
    if(headCD == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR DOUBLY LINKED LIST IS EMPTY.                                       |\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    Node *temp = headCD;
    Node *temp1;

    int key;
    printf("         -> | Enter node data to delete the node.                                         |\n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    while(temp->DATA!=key){
        temp1 = temp;
        temp = temp->next;
        if(temp->next == headCD && temp->DATA!=key){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.                                                |\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
    }

    if(temp == headCD){
        if(temp->next == headCD && temp->prev == headCD){
            headCD = NULL;
            free(temp);
        } else{
            temp1 = headCD;
            while(temp->next!=headCD){
                temp = temp->next;
            }
            headCD = temp1->next;
            temp->next = headCD;
            headCD->prev = temp;
            temp1->next = NULL;
            temp1->prev = NULL;
            free(temp1);
        }
    } else{
        temp1->next = temp->next;
        temp1->next->prev = temp1;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE DELETED.                                                               |\n");
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
        
        printf("         -> | Choose one of the following options:                                        |\n");
        printf("          0 | Exit current menu.                                                          |\n");
        printf("          1 | Double Linked List.                                                         |\n");
        printf("          2 | Circular Doubly Linked List.                                                |\n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);
        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Insert node in a Double Linked List:                     |\n");
                    printf("          0 | Exit current menu.                                                          |\n");
                    printf("          1 | Insert node at Beginning.                                                   |\n");
                    printf("          2 | Insert node at Specified Location.                                          |\n");
                    printf("          3 | Insert node at End.                                                         |\n");
                    printf("          4 | Display Single Linked List.                                                 |\n");
                    printf("          5 | Delete node at Beginning.                                                   |\n");
                    printf("          6 | Delete node at Specified Location.                                          |\n");
                    printf("          7 | Delete node at End.                                                         |\n");
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
                        case 5: {
                            deleteAtBeginningD();
                            break;
                        }
                        case 6: {
                            deleteAtLocationD();
                            break;
                        }
                        case 7: {
                            deleteAtEndD();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | DOUBLE LINKED LIST MENU EXITED.                                             |\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                             |\n");
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
                    
                    printf("         -> | Choose a option to Insert node in a Circular Doubly Linked List:            |\n");
                    printf("          0 | Exit current menu.                                                          |\n");
                    printf("          1 | Insert node at Beginning.                                                   |\n");
                    printf("          2 | Insert node at specified Location.                                          |\n");
                    printf("          3 | Insert node at End.                                                         |\n");
                    printf("          4 | Display Circular Linked List.                                               |\n");
                    printf("          5 | Delete node at Beginning.                                                   |\n");
                    printf("          6 | Delete node at Specified Location.                                          |\n");
                    printf("          7 | Delete node at End.                                                         |\n");
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
                        case 5: {
                            deleteAtBeginningCD();
                            break;
                        }
                        case 6: {
                            deleteAtLocationCD();
                            break;
                        }
                        case 7: {
                            deleteAtEndCD();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | CIRCULAR DOUBLY LINKED LIST MENU EXITED.                                    |\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                             |\n");
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
                printf("        !!! | PROGRAM TERMINATED.                                                         |\n");
                printf("            ===============================================================================\n");
                break;
            }
            default: {
                printf("            |-----------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                             |\n");
                printf("            |-----------------------------------------------------------------------------|\n");
                break;
            }
        }
        
    }

    return 0;
}