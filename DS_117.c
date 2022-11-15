#include<stdio.h>  
#include<stdlib.h>  

int found = 0;
int nodes = 0;
int tree = 0;

struct node{  
    int key;  
    struct node *left;  
    struct node *right;  
};  

struct node *getNode(int val){  
    struct node *newNode;  
  
    newNode = malloc(sizeof(struct node));  
  
    newNode->key   = val;  
    newNode->left  = NULL;  
    newNode->right = NULL;  
  
    return newNode;  
}  

struct node *insertNode(struct node *root, int val){  
     if(root == NULL)  
         return getNode(val);  
  
     if(root->key < val)  
         root->right = insertNode(root->right,val);  
  
     if(root->key > val)  
         root->left = insertNode(root->left,val);  
  
     return root;  
}  

void inorder(struct node *root, int key){  
    if(root == NULL)  
        return;  
  
    inorder(root->left, key);
    if(root->key == key){
        found = 1;
    }
    printf(" %d |",root->key);  
    inorder(root->right, key);  
    return;
} 

void preorder(struct node *root){  
    if(root == NULL)  
        return;  
   
    printf(" %d |",root->key);  
    preorder(root->left);  
    preorder(root->right); 
    return; 
}

void postorder(struct node *root){  
    if(root == NULL)  
        return;  

    postorder(root->left);  
    postorder(root->right);  
    printf(" %d |",root->key);  
    return;
}

struct node* minValueNode(struct node* node){
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

struct node* deleteNode(struct node* root, int key){
    if (root == NULL){
        tree = 1;
        return root;
    }
  
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if (root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()  
{  
    struct node *root = NULL;  

    int Menu = 1;
    
    printf("            =======================================================================================\n");
    printf("            | Welcome User!    This is a program to Implement Operations on Binary Search Tree.   |\n");
    printf("            =======================================================================================\n");

    while(Menu){
        int MenuOption;
        printf("         -> | Choose a option to Insert node in a Single Linked List:                             |\n");
        printf("          0 | Exit current menu.                                                                  |\n");
        printf("          1 | Insert Node in Binary Search Tree.                                                  |\n");
        printf("          2 | Delete Node in Binary Search Tree.                                                  |\n");
        printf("          3 | Search a Node in Tree.                                                              |\n");
        printf("          4 | Inorder Traversal of Tree.                                                          |\n");
        printf("          5 | Preorder Traversal of Tree.                                                         |\n");
        printf("          6 | Postorder Traversal of Tree.                                                        |\n");
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
                int val;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("         -> | Enter Node Data for Deletion in BST.                                                |\n");
                printf("    Element | ");
                scanf("%d", &val);
                root = deleteNode(root,val);
                if(tree == 1){
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | TREE EMPTY.                                                                         |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | NODE DELETED                                                                        |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    nodes -= 1;
                }
                break;
            }
            case 3: {
                int val;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("         -> | Enter Node Data for Search in BST.                                                  |\n");
                printf("    Element | ");
                scanf("%d", &val);
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("Binary Tree | ");
                inorder(root, val);
                printf("\n");
                if(found){
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | NODE DATA FOUND.                                                                    |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                } else{
                    printf("            |-------------------------------------------------------------------------------------|\n");
                    printf("          ! | NODE DATA NOT FOUND.                                                                |\n");
                    printf("            |-------------------------------------------------------------------------------------|\n");
                }
                break;
            }
            case 4: {
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("Binary Tree | ");
                inorder(root, -1);
                printf("\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
                break;
            }
            case 5: {
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("Binary Tree | ");
                preorder(root);
                printf("\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
                break;
            }
            case 6: {
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("Binary Tree | ");
                postorder(root);
                printf("\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
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