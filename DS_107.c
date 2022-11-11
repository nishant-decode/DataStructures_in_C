#include <stdio.h>
#include <stdlib.h>

//defining node structure
typedef struct node{
    int DATA;
    struct node *next;
}Node;

//initialising nodes out of main for global scope
Node *headF = NULL;
Node *headS = NULL;
Node *headM = NULL;

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
        printf("       List |");
        while (temp != NULL){
            printf(" %d |", temp->DATA);
            temp = temp->next;
        }

        printf("\n            |------------------------------------------------------------------------------|\n"); 
    }
    return;
}

struct node *insertNode(Node *head){
    int val;
    printf("         -> | Enter data for node insertion.                                               |\n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (head == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        head = temp;
    } else{
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp1->next = NULL;
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        if(val < temp->DATA){
            printf("            |------------------------------------------------------------------------------|\n");
            printf("          ! | ENTER VALUE GREATER THAN EQUAL TO LAST NODE DATA FOR A SORTED LIST.          |\n");
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

void mergeLinkedLists(){
    Node *temp = headF;
    Node *temp1 = headS;
    
    
    if(headF == NULL){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | FIRST LINKED LIST EMPTY. CREATE LIST.                                        |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }
    if(headS == NULL){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | SECOND LINKED LIST EMPTY. CREATE LIST.                                       |\n");
        printf("            |------------------------------------------------------------------------------|\n");
        return;
    }

    Node *temp2 = (Node *)malloc(sizeof(Node));
    if (headF->DATA < headS->DATA){
        temp2->DATA = temp->DATA;
        temp2->next = NULL;
        temp = headF->next;
        headM = temp2;
    } else{
        temp2->DATA = temp1->DATA;
        temp2->next = NULL;
        temp1 = headS->next;
        headM = temp2;
    }

    while (temp != NULL && temp1 != NULL){
        Node *temp3 = (Node *)malloc(sizeof(Node));
        if (temp->DATA < temp1->DATA){
            temp3->DATA = temp->DATA;
            temp3->next = NULL;
            temp2->next = temp3;
            temp2 = temp3;
            temp = temp->next;
        } else{
            temp3->DATA = temp1->DATA;
            temp3->next = NULL;
            temp2->next = temp3;
            temp2 = temp3;
            temp1 = temp1->next;
        }
    }
    
    if(temp1 == NULL){
        while (temp != NULL){
            Node *temp3 = (Node *)malloc(sizeof(Node));
            temp3->DATA = temp->DATA;
            temp3->next = NULL;
            temp2->next = temp3;
            temp2 = temp3;
            temp = temp->next;
        }
    }

    if(temp == NULL){
        while (temp1 != NULL){
            Node *temp3 = (Node *)malloc(sizeof(Node));
            temp3->DATA = temp1->DATA;
            temp3->next = NULL;
            temp2->next = temp3;
            temp2 = temp3;
            temp1 = temp1->next;
        }
    }
    
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | LINKED LISTS MERGED.                                                         |\n");
    printf("            |------------------------------------------------------------------------------|\n");
    displayList(headM);
    return;
}

int main(){
    int mainMenu = 1;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This is a Menu driven program to Merge two sorted Linked Lists |\n");
    printf("            ================================================================================\n");

    while(mainMenu){
        int mainMenuOption;
        
        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Create First Sorted Single Linked List.                                      |\n");
        printf("          2 | Create Second Sorted Single Linked List.                                     |\n");
        printf("          3 | Merge the two sorted Linked Lists.                                           |\n");
        printf("          4 | Display Merged Sorted Linked List.                                           |\n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);

        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;
                    
                    printf("         -> | Choose a option to create the First Sorted Linked List:                      |\n");
                    printf("          0 | Exit current menu.                                                           |\n");
                    printf("          1 | Insert node.                                                                 |\n");
                    printf("          2 | Display Sorted Linked List.                                                  |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1: {
                            headF = insertNode(headF);
                            break;
                        }
                        case 2: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            displayList(headF);
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("         !! | FIRST LINKED LIST MENU EXITED.                                               |\n");
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
                    
                    printf("         -> | Choose a option to create the Second Sorted Linked List:                     |\n");
                    printf("          0 | Exit current menu.                                                           |\n");
                    printf("          1 | Insert node.                                                                 |\n");
                    printf("          2 | Display Sorted Linked List.                                                  |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1: {
                            headS = insertNode(headS);
                            break;
                        }
                        case 2: {
                            printf("            |------------------------------------------------------------------------------|\n");
                            displayList(headS);
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------|\n");
                            printf("         !! | SECOND LINKED LIST MENU EXITED.                                              |\n");
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
                mergeLinkedLists();
                break;
            }
            case 4: {
                printf("            |------------------------------------------------------------------------------|\n");
                displayList(headM);
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