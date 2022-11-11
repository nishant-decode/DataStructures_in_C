#include <stdio.h>
#include <stdlib.h>

//defining node structure
typedef struct node{
    int DATA;
    struct node *next;
}Node;

//initialising node out of main for global scope
Node *head = NULL;

void displayList(){
    Node *temp = head;

    if (temp == NULL)
    {
        printf("          ! | LINKED LIST IS EMPTY.\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf("       List |");
        while (temp != NULL){
            printf(" %d |", temp->DATA);
            temp = temp->next;
        }

        printf("\n            |-------------------------------------------------------------------------------------|\n"); 
    }
    return;
}

void insertAtBeginning(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (head == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        head = temp;
    } else{
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = head;
        head = temp;
    }

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.                                                                      |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    displayList();
    return;
}

void insertAtEnd(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
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
        temp->next = temp1;
    }

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.                                                                      |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    displayList();
    return;
}

void insertAtLocation(){
    
    int key;
    printf("         -> | Enter node data to link the node after.                                             |\n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(head == NULL){
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | SINGLE LINKED LIST IS EMPTY.                                                        |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }

    Node *temp = head;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while((temp->DATA)!=key){
        if(temp->next == NULL){
            printf("            |-------------------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.                                                        |\n");
            printf("            |-------------------------------------------------------------------------------------|\n");
            return;
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        insertAtEnd();
        return;
    } else{
        int val;
        printf("         -> | Enter data for node insertion.                                                      |\n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node *temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
    }
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.                                                                      |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    displayList();
    return;
}

void linkedListLength(){
    int count = 0;

    Node *temp = head;
   
    while(temp != NULL){
        count += 1;
        temp = temp->next;
    }

    if(count == 0){
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | SINGLE LINKED LIST IS EMPTY, NUMBER OF NODES IS ZERO.                               |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
    } else{
        printf("List Length | %d\n", count);
    }
    return;
}

void reverseLinkedList(){
    Node *headR = NULL;
    Node *temp = head;
    Node *temp1;

    if(head == NULL){
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | SINGLE LINKED LIST IS EMPTY.                                                        |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }else if(head->next != NULL){
        while(temp!=NULL){
            temp = temp->next;
            temp1 = head;
            head = head->next;
            temp1->next = headR;
            headR = temp1;
        }
        head = headR;
    }

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | SINGLE LINKED LIST REVERSED.                                                        |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");

    displayList();
    return;
}

int main(){
    int Menu = 1;
    
    printf("            =======================================================================================\n");
    printf("            | Welcome User! This is a program to count and reverse nodes in a Single Linked Lists |\n");
    printf("            =======================================================================================\n");

    while(Menu){
        int MenuOption;
        printf("         -> | Choose a option to Insert node in a Single Linked List:                             |\n");
        printf("          0 | Exit current menu.                                                                  |\n");
        printf("          1 | Insert node at Beginning.                                                           |\n");
        printf("          2 | Insert node at specified Location.                                                  |\n");
        printf("          3 | Insert node at End.                                                                 |\n");
        printf("          4 | Display Single Linked List.                                                         |\n");
        printf("          5 | Display the number of nodes in List.                                                |\n");
        printf("          6 | Reverse the List.                                                                   |\n");
        printf("Enter Index | ");
        scanf("%d", &MenuOption);
        switch(MenuOption){
            case 1: {
                insertAtBeginning();
                break;
            }
            case 2: {
                insertAtLocation();
                break;
            }
            case 3: {
                insertAtEnd();
                break;
            }
            case 4: {
                printf("            |-------------------------------------------------------------------------------------|\n");
                displayList();
                break;
            }
            case 5: {
                linkedListLength();
                break;
            }
            case 6: {
                reverseLinkedList();
                break;
            }
            case 0: {
                Menu = 0;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.                                                                 |\n");
                printf("            =======================================================================================\n");
                break;
            }
            default: {
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                                     |\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
                break;
            }
        }
    }
    return 0;
}