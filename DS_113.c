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
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
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
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS FULL.                                                               |\n");
        printf("            |------------------------------------------------------------------------------|\n");
		return;
    }
    
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | %d ENQUEUED TO QUEUE.                                                         \n", item);
    printf("            |------------------------------------------------------------------------------|\n");
}

void dequeue(struct Queue* queue){
	if (isEmpty(queue)){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS EMPTY.                                                              |\n");
        printf("            |------------------------------------------------------------------------------|\n");
		return;
    }
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | %d DEQUEUED FROM QUEUE.                                                       \n", item);
    printf("            |------------------------------------------------------------------------------|\n");

	return;
}

void front(struct Queue* queue){
	if (isEmpty(queue)){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS EMPTY.                                                              |\n");
        printf("            |------------------------------------------------------------------------------|\n");
		return;
    }
    printf("            |------------------------------------------------------------------------------|\n");
    printf("          ! | %d IS FRONT ELEMENT OF QUEUE.                                                 \n",  queue->array[queue->front]);
    printf("            |------------------------------------------------------------------------------|\n");
	return;
}

void rear(struct Queue* queue){
	if (isEmpty(queue)){
        printf("            |------------------------------------------------------------------------------|\n");
        printf("          ! | QUEUE IS EMPTY.                                                              |\n");
        printf("            |------------------------------------------------------------------------------|\n");
		return;
    }
    printf("          ! | %d IS REAR ELEMENT OF QUEUE.                                                  \n", queue->array[queue->rear]);
    printf("            |------------------------------------------------------------------------------|\n");
	return;
}

int main(){
    int menu = 1;
    int queueCreated = 0;
    
    printf("            ================================================================================\n");
    printf("            | Welcome User! This is a Menu driven program to implement Queues using Arrays |\n");
    printf("            ================================================================================\n");

    while(menu){
        int menuOption;
        struct Queue* queue;

        printf("         -> | Choose one of the following options:                                         |\n");
        printf("          0 | Exit current menu.                                                           |\n");
        printf("          1 | Create Queue using Arrays.                                                   |\n");
        printf("          2 | Enqueue elements in Queue.                                                   |\n");
        printf("          3 | Dequeue elements from Queue.                                                 |\n");
        printf("          4 | Check status of the Queue for Empty or Full.                                 |\n");
        printf("          5 | Check Front and Rear element of the Queue.                                   |\n");
        printf("Enter Index | ");
        scanf("%d", &menuOption);

        switch(menuOption){
            case 1: 
                queue = createQueue(100);
                queueCreated = 1;
                break;
            case 2: 
                printf("            |------------------------------------------------------------------------------|\n");
                if(queueCreated == 1){
                    int val;
                    printf("         -> | Enter element to enqueue in Queue.                                           |\n");
                    printf("    Element | ");
                    scanf("%d", &val);
                    enqueue(queue, val);
                } else{
                    printf("          ! | FIRST CREATE QUEUE.                                                          |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 3: 
                if(queueCreated == 1){
                    dequeue(queue);
                } else{
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | FIRST CREATE QUEUE.                                                          |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 4:
                if (isFull(queue)){
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | QUEUE IS FULL.                                                               |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                } else if (isEmpty(queue)){
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | QUEUE IS EMPTY.                                                              |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |------------------------------------------------------------------------------|\n");
                    printf("          ! | QUEUE NEITHER FULL NOR EMPTY.                                                |\n");
                    printf("            |------------------------------------------------------------------------------|\n");
                }
                break;
            case 5:
                if(!isEmpty(queue)){
                    front(queue);
                    rear(queue);
                }
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
