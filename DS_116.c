#include <stdio.h>
#include <stdlib.h>

int* array; 
int* sparseArray;
int size = 0, rows, columns;

void createMatrix(){
    int i,j,limit=0;

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("            | Enter the dimensions of the Matrix.                                                 |\n");
    printf("       Rows | ");
    scanf("%d", &rows);
    printf("    Columns | ");
    scanf("%d", &columns);
    
    array = (int*)malloc(rows*columns*sizeof(int));

    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("            | Enter the Elements of the Matrix.                                                   |\n");
    for(i = 0; i < rows*columns; i+=columns){
        limit += columns;
        printf("     Rows %d | ", i/columns);
        for(j = i; j < limit; j++){
            scanf("%d" , &array[j]);
        }
        
    }

	for (i = 0; i < rows*columns; i++)
		if (array[i] != 0)
			size++;
    
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | MATRIX CRREATED.                                                                    |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    return;
}

void displaySparseArray(){
    int limit = size;

    if(size == 0){
        printf("          ! | ARRAY EMPTY.                                                                        |\n");
        printf("            |-------------------------------------------------------------------------------------|\n");
        return;
    }
    printf("            | Displaying Sparse Matrix.                                                           |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    for (int i = 0; i < 3*size; i+=size){
        if(i == 0){
            printf("        Row | ");
        } else if(i/size == 1){
            printf("     Column | ");
        } else{
            printf("      Value | ");
        }
		for (int j = i; j < limit; j++)
			printf(" %d ", sparseArray[j]);

		printf("\n");
        limit += size;
	}
    printf("            |-------------------------------------------------------------------------------------|\n");
    return;
}

void sparseMatrix(){
	int k = 0,i,j,limit = columns;

    sparseArray = (int*)malloc(3*size*sizeof(int));

	for (i = 0; i < rows*columns; i+=columns){
        for(j = i; j < limit; j++)
			if (array[j] != 0){
				sparseArray[k] = i/columns;
				sparseArray[k+size] = j%columns;
				sparseArray[k+(2*size)] = array[j];
				k++;
			}
        limit += columns;
    }
    printf("            |-------------------------------------------------------------------------------------|\n");
    printf("          ! | SPARSE ARRAY CRREATED.                                                              |\n");
    printf("            |-------------------------------------------------------------------------------------|\n");
    displaySparseArray();
    return;
}

int main(){
    int Menu = 1;
    
    printf("            =======================================================================================\n");
    printf("            | Welcome User!  This is a Menu driven program to convert a Matrix to Sparse Array.   |\n");
    printf("            =======================================================================================\n");

    while(Menu){
        int MenuOption;
        printf("         -> | Choose a option to Insert node in a Single Linked List:                             |\n");
        printf("          0 | Exit current menu.                                                                  |\n");
        printf("          1 | Input a Matrix or 2D Array.                                                         |\n");
        printf("          2 | Convert the Matrix into a Sparse Array                                              |\n");
        printf("          3 | Display the Sparse Array.                                                           |\n");
        printf("Enter Index | ");
        scanf("%d", &MenuOption);
        switch(MenuOption){
            case 1:
                createMatrix();
                break;
            case 2:
                sparseMatrix();
                break;
            case 3:
                printf("            |-------------------------------------------------------------------------------------|\n");
                displaySparseArray();
                break;
            case 0:
                Menu = 0;
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.                                                                 |\n");
                printf("            =======================================================================================\n");
                break;
            default:
                printf("            |-------------------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.                                                                     |\n");
                printf("            |-------------------------------------------------------------------------------------|\n");
                break;
        }
    }
	return 0;
}