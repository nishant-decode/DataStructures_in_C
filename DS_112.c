#include <stdio.h>

int array[100];
int length;

void insertElement(){
    int element;
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("         -> | Enter element to insert in Array. \n");
    printf("    Element | ");
    scanf("%d", &element);

    array[length] = element;
    length += 1;
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | ELEMENT INSERTED IN ARRAY.                                                          |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    return;
}

void displayArray(){
    int i = 0;

    if(length == 0){
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | ARRAY EMPTY.                                                                        |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("      Array | ");
    while(i<length){
        printf("%d | ", array[i]);
        i += 1;
    }
    printf("\n            |-------------------------------------------------------------------------------------|\n");

    return;
}

void insertionSort(){
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//Binary Search function
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l)/2;

        if (arr[mid] == x) 
            return mid;
        else if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
        else 
            return binarySearch(arr, mid+1, r, x);

    }
    return -1;
}

void searchElement(){
    int result;

    if (length == 0)
    {
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | ARRAY IS EMPTY.                                                                     |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }

    int key;
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("         -> | Enter element to find in Array. \n");
    printf("    Element | ");
    scanf("%d", &key);

    insertionSort();

    result = binarySearch(array, 0, length, key);

    if(result == -1){
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | ELEMENT NOT FOUND.                                                                  |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    } else{
        printf("            |-------------------------------------------------------------------------------------|\n");
        printf("          ! | ELEMENT FOUND AT INDEX %d.                                                           \n", result);
    }

    displayArray();
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
        printf("          1 | Insert elements in Array.                                                           |\n");
        printf("          2 | Display the Array.                                                                  |\n");
        printf("          3 | Search an element in Array using Binary Search.                                     |\n");
        printf("Enter Index | ");
        scanf("%d", &MenuOption);
        switch(MenuOption){
            case 1: {
                insertElement();
                break;
            }
            case 2: {
                displayArray();
                break;
            }
            case 3: {
                searchElement();
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