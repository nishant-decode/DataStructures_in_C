#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
    queue->size = 0;
    queue->front = -1;
	queue->rear = - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue){
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue){
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item){
	if (isFull(queue)){
        printf("            |------------------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS FULL.                                                                           |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
		return;
    }

    if (queue->front == -1) queue->front = 0;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;

	printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d ENQUEUED TO QUEUE.                                                                     \n", item);
    printf("            |------------------------------------------------------------------------------------------|\n");
    return;
}

void dequeue(struct Queue* queue){
    int element;
	if (isEmpty(queue)){
        printf("            |------------------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
		return;
    } else {
        element = queue->array[queue->front];
    }

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
        queue->size = queue->size - 1;
    } else{
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
    }

    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d DEQUEUED FROM QUEUE.                                                                   \n", element);
    printf("            |------------------------------------------------------------------------------------------|\n");

	return;
}

void displayQueue(struct Queue* queue) {
    int i;
    if (isEmpty(queue)){
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
        return;
    }
    printf("      Queue | Front -> |");
    if (queue->rear >= queue->front){
        for (int i = queue->front; i <= queue->rear; i++)
            printf(" %d |",queue->array[i]);
    } else{
        for (int i = queue->front; i < queue->capacity; i++)
            printf(" %d |", queue->array[i]);
  
        for (int i = 0; i <= queue->rear; i++)
            printf(" %d |", queue->array[i]);
    }
    printf(" <- Rear\n");
    printf("            |------------------------------------------------------------------------------------------|\n");
    return;
}

/* LINKED LIST IMPLEMENTATION OF CIRCULAR LIST */

struct node{
	int data;
	struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;
int size;

void enqueueL(int val){
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = val;
	temp->next = NULL;

	if((rear==NULL)&&(front==NULL)){
		front = rear = temp;
		rear->next = front;
	} else{
		rear->next = temp;
		rear = temp;
		temp->next = front;
	}
    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d ENQUEUED TO QUEUE.                                                                     \n", temp->data);
    printf("            |------------------------------------------------------------------------------------------|\n");
    return;
}

void dequeueL(){
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
		rear->next = front;
	}
    printf("            |------------------------------------------------------------------------------------------|\n");
    printf("          ! | %d DEQUEUED FROM QUEUE.                                                                   \n", temp->data);
    printf("            |------------------------------------------------------------------------------------------|\n");
    free(temp);
    return;
}

void displayQueueL(){
	struct node* temp = front;

	if((front==NULL)&&(rear==NULL)){
        printf("          ! | QUEUE IS EMPTY.                                                                          |\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
	} else{
        printf("      Queue | Front -> |");
		while(temp != rear){
			printf(" %d |", temp->data);
			temp = temp->next;
		}
        printf(" %d |", temp->data);
        printf(" <- Rear\n");
        printf("            |------------------------------------------------------------------------------------------|\n");
	}
}

int main(){
    int mainMenu = 1;
    
    printf("            ============================================================================================\n");
    printf("            | Welcome User! This is a program to Implement Circular Queue using Arrays and Linked List |\n");
    printf("            ============================================================================================\n");

    while(mainMenu){
        int mainMenuOption;

        printf("         -> | Choose one of the following options:                                                     |\n");
        printf("          0 | Exit current menu.                                                                       |\n");
        printf("          1 | Create a Circular Queue using Arrays.                                                    |\n");
        printf("          2 | Create a Circular Queue using Linked Lists.                                              |\n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);
        printf("            |------------------------------------------------------------------------------------------|\n");

        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                struct Queue* queue = createQueue(10);

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Create a Circular Queue using Arrays:                                 |\n");
                    printf("          0 | Exit current menu.                                                                       |\n");
                    printf("          1 | Enqueue elements in Queue.                                                               |\n");
                    printf("          2 | Dequeue elements from Queue.                                                             |\n");
                    printf("          3 | Display Circular Queue.                                                                  |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);

                    switch(subMenuOption){
                        case 1:
                            int val;
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            printf("         -> | Enter element to enqueue in Queue.                                                       |\n");
                            printf("    Element | ");
                            scanf("%d", &val);
                            enqueue(queue, val);
                            break;
                        case 2:
                            dequeue(queue);
                            break;
                        case 3:
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            displayQueue(queue);
                            break;
                        case 0:
                            subMenu = 0;
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            printf("         !! | CIRCULAR QUEUE (ARRAY) MENU EXITED.                                                      |\n");
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

                struct Queue* queue = createQueue(100);

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Create a Circular Queue using Linked Lists:                           |\n");
                    printf("          0 | Exit current menu.                                                                       |\n");
                    printf("          1 | Enqueue elements in Queue.                                                               |\n");
                    printf("          2 | Dequeue elements from Queue.                                                             |\n");
                    printf("          3 | Check status of the Queue for Empty or Full.                                             |\n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1:
                            int val;
                            printf("         -> | Enter element to enqueue in Queue.                                                       |\n");
                            printf("    Element | ");
                            scanf("%d", &val);
                            enqueueL(val);
                            break;
                        case 2:
                            dequeueL();
                            break;
                        case 3:
                            printf("            |------------------------------------------------------------------------------------------|\n");
                            displayQueueL();
                            break;
                        case 0:
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------------------|\n");
                            printf("         !! | CIRCULAR QUEUE (LINKED LIST) MENU EXITED.                                               |\n");
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