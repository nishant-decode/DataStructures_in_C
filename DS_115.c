#include <stdio.h>
#include <stdlib.h>

/* LINKED LIST IMPLEMENTATION OF QUEUE */

struct node{
	int DATA;
	struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val){
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->DATA = val;
	temp->next = NULL;

	if((rear==NULL)&&(front==NULL)){
		front = rear = temp;
	} else{
		rear->next = temp;
		rear = temp;
	}
    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d ENQUEUED TO QUEUE.                                                                     \n", temp->DATA);
    printf("            |------------------------------------------------------------------------------------------|\n");
    return;
}

void dequeue(){
	struct node* temp = front;

	if((front==NULL)&&(rear==NULL)){
		printf("            |------------------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
        return;
	} else if(front == rear){
		front = rear = NULL;
	} else{
		front = front->next;
	}
    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d DEQUEUED FROM QUEUE.                                                                   \n", temp->DATA);
    printf("            |------------------------------------------------------------------------------------------|\n");
    free(temp);
    return;
}

void displayQueue(){
	struct node* temp = front;

	if((front==NULL)&&(rear==NULL)){
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
	} else{
        printf("      Queue | Front -> |");
		while(temp != NULL){
			printf(" %d |", temp->DATA);
			temp = temp->next;
		}
        printf(" <- Rear\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
	}
}

/* LINKED LIST IMPLEMENTATION OF STACK */

struct node *TOS = NULL;

void push(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->DATA = val;
    temp->next = TOS;
    TOS = temp;

    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d PUSHED TO STACK.                                                                       \n", temp->DATA);
    printf("            |------------------------------------------------------------------------------------------|\n");
    return; 
}

void pop(){
    struct node *temp;

    if(TOS == NULL){
        printf("            |------------------------------------------------------------------------------------------|\n");
        printf("          ! | STACK UNDERFLOW.                                                                         |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
        return;
    }
    
    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d POPED FROM STACK.                                                                      \n", TOS->DATA);
    printf("            |------------------------------------------------------------------------------------------|\n");

    temp = TOS;
    TOS = TOS->next;
    free(temp);
    return;
}

void displayStack(){
    struct node *temp = TOS;

    if(TOS == NULL){
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
        return;
	}

    printf("      Stack |");
    while(temp != NULL)
    {
        printf(" %d -> ", temp->DATA);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("            |------------------------------------------------------------------------------------------|\n");
    return;
}

int main(){
    int mainMenu = 1;
    
    printf("            ============================================================================================\n");
    printf("            | Welcome User! This is Menu Driven program to Implement Stack and Queue using Linked List |\n");
    printf("            ============================================================================================\n");

    while(mainMenu){ 
        int mainMenuOption;

        printf("         -> | Choose one of the following options:                                                     |\n");
        printf("          0 | Exit current menu.                                                                       |\n");
        printf("          1 | Create a Stack using Linked Lists.                                                       |\n");
        printf("          2 | Create a Queue using Linked Lists.                                                       |\n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);
        printf("            |------------------------------------------------------------------------------------------|\n");

        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Create a Stack using Linked List:                                     |\n");
                    printf("          0 | Exit current menu.                                                                       |\n");
                    printf("          1 | Push elements in Stack.                                                                  |\n");
                    printf("          2 | Pop elements from Stack.                                                                 |\n");
                    printf("          3 | Display Stack.                                                                           |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1:{
                            int val;
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            printf("         -> | Enter element to push in Stack.                                                          |\n");
                            printf("    Element | ");
                            scanf("%d", &val);
                            push(val);
                        }
                            break;
                        case 2:
                            pop();
                            break;
                        case 3:
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            displayStack();
                            break;
                        case 0:
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            printf("         !! | STACK MENU EXITED.                                                                       |\n");
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            break;
                        default:
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                                          |\n");
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            break;
                    }
                }
                break;
            }
            case 2:{
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Create a Queue using Linked Lists:                                    |\n");
                    printf("          0 | Exit current menu.                                                                       |\n");
                    printf("          1 | Enqueue elements in Queue.                                                               |\n");
                    printf("          2 | Dequeue elements from Queue.                                                             |\n");
                    printf("          3 | Display Queue.                                                                           |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1: {
                            int val;
                            printf("         -> | Enter element to enqueue in Queue.                                                       |\n");
                            printf("    Element | ");
                            scanf("%d", &val);
                            enqueue(val);
                        }
                            break;
                        case 2:
                            dequeue();
                            break;
                        case 3:
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            displayQueue();
                            break;
                        case 0:
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------------------|\n");
                            printf("         !! |  QUEUE MENU EXITED.                                                                     |\n");
                            printf("            |-----------------------------------------------------------------------------------------|\n");
                            break;
                        default:
                            printf("            |-----------------------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.                                                                         |\n");
                            printf("            |-----------------------------------------------------------------------------------------|\n");
                            break;
                    }
                }
                break;
            }
            case 0:
                mainMenu = 0;
                printf("            |------------------------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.                                                                      |\n");
                printf("            ============================================================================================\n");
                break;
            default:
                printf("            |------------------------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                                          |\n");
                printf("            |------------------------------------------------------------------------------------------|\n");
                break;
        }
        
    }
  
    return 0;
}