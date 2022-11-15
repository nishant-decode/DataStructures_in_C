#include<stdio.h>
#include<stdlib.h>
#define bool int

int nodes = 0;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Stack{
	struct Node *t;
	struct Stack *next;
};

struct Node *getNode(int val){  
    struct Node *newNode;  
  
    newNode = malloc(sizeof(struct Node));  
  
    newNode->data   = val;  
    newNode->left  = NULL;  
    newNode->right = NULL;  
  
    return newNode;  
} 

struct Node *insertNode(struct Node *root, int val){  
    if(root == NULL)  
        return getNode(val);  
      
    if(root->data < val)  
        root->right = insertNode(root->right,val);  
  
    if(root->data > val)  
        root->left = insertNode(root->left,val);  
  
    return root;  
}  

void push(struct Stack** top_ref, struct Node *t){
	struct Stack* new_Node =(struct Stack*) malloc(sizeof(struct Stack));
	if(new_Node == NULL){
		printf("Stack Overflow \n");
		getchar();
		exit(0);
	}			

	new_Node->t = t;
	new_Node->next = (*top_ref);
	(*top_ref) = new_Node;
}

bool isEmpty(struct Stack *top){
	return (top == NULL)? 1 : 0;
}

struct Node *pop(struct Stack** top_ref){
	struct Node *res;
	struct Stack *top;

	if(isEmpty(*top_ref)){
		printf("Stack Underflow \n");
		getchar();
		exit(0);
	}
	else{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}


void inorder(struct Node *root){
	struct Node *current = root;
	struct Stack *s = NULL;
	bool done = 0;

	while (!done){
		if(current != NULL){
			push(&s, current);											
			current = current->left;
		} else{
			if (!isEmpty(s)){
				current = pop(&s);
				printf("%d ", current->data);
				current = current->right;
		} else
			done = 1;
		}
	}
}	

// create preorder and postorder
void preorder(struct Node *root){
	struct Node *current = root;
	struct Stack *s = NULL;
	bool done = 0;

	while (!done){
		if(current != NULL){
			push(&s, current);											
			current = current->left;
		} else{
			if (!isEmpty(s)){
				current = pop(&s);
				printf("%d ", current->data);
				current = current->right;
		} else
			done = 1;
		}
	}
}

void postorder(struct Node *root){
	struct Node *current = root;
	struct Stack *s = NULL;
	bool done = 0;

	while (!done){
		if(current != NULL){
			push(&s, current);											
			current = current->left;
		} else{
			if (!isEmpty(s)){
				current = pop(&s);
				printf("%d ", current->data);
				current = current->right;
		} else
			done = 1;
		}
	}
}

int main(){
    struct Node *root = NULL;  

    int Menu = 1;
    
    printf("            =======================================================================================\n");
    printf("            | Welcome User!    This is a program to Implement Operations on Binary Search Tree.   |\n");
    printf("            =======================================================================================\n");

    while(Menu){
        int MenuOption;
        printf("         -> | Choose a option to Insert node in a Single Linked List:                             |\n");
        printf("          0 | Exit current menu.                                                                  |\n");
        printf("          1 | Insert Node in Binary Search Tree.                                                  |\n");
        printf("          2 | Inorder Traversal of Tree.                                                          |\n");
        printf("          3 | Preorder Traversal of Tree.                                                         |\n");
        printf("          4 | Postorder Traversal of Tree.                                                        |\n");
        printf("Enter Index | ");
        scanf("%d", &MenuOption);
        switch(MenuOption){
            case 1: {
                int val;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("         -> | Enter Node Data for Insertion in BST.                                               |\n");
                printf("    Element | ");
                scanf("%d", &val);
                root = insertNode(root,val);
                nodes += 1;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("          ! | NODE INSERTED.                                                                      |\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
                break;
            }
            case 2: {
                if(nodes){
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("Binary Tree | ");
                    inorder(root);
                    printf("\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | EMPTY TREE.                                                                         |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                }
                break;
            }
            case 3: {
                if(nodes){
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("Binary Tree | ");
                    preorder(root);
                    printf("\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | EMPTY TREE.                                                                         |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                }
                break;
            }
            case 4: {
                if(nodes){
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("Binary Tree | ");
                    postorder(root);
                    printf("\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | EMPTY TREE.                                                                         |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                }
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
