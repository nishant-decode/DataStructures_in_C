#include <stdio.h>
#include <stdlib.h>

int arr[10];
int count = 0;

void insertion()
{
    int choice;
    int loc;
    int data;
    int end;
    printf( "\n1.Enter data at beginning\n");
    printf( "2.Enter data at a specific location\n");
    printf( "3.Enter data at the end\n");
    printf( "Choose any one option : ");
    scanf("%d", &choice);

    if(choice>3)
        printf("Invalid Option\n\n");

    else{
    switch (choice)
    {
    case 1:
    {
        int element1;
        printf( "Enter data : ");
        scanf("%d", &element1);
        for (int i = count - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = element1;
        count++;
        break;
    }
    case 2:
    {
        if (count == 0)
        {
            printf( "Array is empty. Cant enter data.\n");
        }
        else if (count == 1)
        {
            printf( "Cant enter data, array contains one element\n\n");
        }
        else
        {
            printf( "Enter the location of the data to be inserted : ");
            scanf("%d",&loc);
            if(loc>count){
                printf("Operation Invalid\n");
            }
            else{
            printf( "Enter data : ");
            scanf("%d",&data);
            for (int i = count - 1; i >= loc - 1; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[loc - 1] = data;
            count++;
        }
        }
        break;
    }
    case 3:
    {
        printf( "Enter data : ");
        scanf("%d",&end);
        arr[count] = end;
        count++;
        break;
    }
    }
}
}

int search(int x)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == x)
            return i + 1;
    }
    return -1;
}

void selectionSort()
{
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        int min_index = i;
        for (j = i + 1; j < count; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
            int temp;
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        
    }
}

void deletion()
{
    int choice;
    int loc;
    int end;
    printf( "\n1.Delete data from beginning\n");
    printf( "2.Delete data from a specific location\n");
    printf( "3.Delete data from the end\n");
    printf( "Choose any one option : ");
    scanf("%d", &choice);

    if(choice>3)
        printf("Invalid Option\n\n");

    else{
        switch (choice)
    {
    case 1:
    {

        for (int i = 0; i < count; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
        break;
    }
    case 2:
    {
        printf( "Enter the location of data for deletion : ");
        scanf("%d", &loc);
        for (int i = loc - 1; i < count; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
    break;
    }
    
    case 3:
    {
        count--;
        break;
    }
}
}
}

int main()
{
    while (5)
    {
        int option;
        printf( "1. insertion\n");
        printf( "2. Traverse\n");
        printf( "3. Linear Search\n");
        printf( "4. Selection Sort\n");
        printf( "5. Delete\n");
        printf( "6. Exit\n");

        printf( "Choose any one option : ");
        scanf("%d", &option);

        if (option > 6)
        {
            printf( "Invalid Option\n\n");
        }
        else
        {
            switch (option)
            {
            case 1:
            {
                insertion();
                break;
            }
            case 2:
            {
                if(count==0)
                    printf("insertion numbers first to traverse through the array\n");
                else{
                printf( "Displaying Array: ");
                for (int i = 0; i < count; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                }
                break;
            }
            case 3:
            {
                int num_search;
                printf( "Enter data for search : ");
                scanf("%d" , &num_search);
                int index = search(num_search);
                if (index == -1)
                    printf( "Data not present in the array\n");
                else
                {
                    printf( "The entered data is present at the %d position\n", index);
                }
                break;
            }
            case 4:
            {
                if(count<2)
                    printf("Can't sort\n");
                else{
                    selectionSort();
                printf( "The sorted array is - \n");
                for (int k = 0; k < count; k++)
                {
                    printf("%d ",arr[k]);
                }
                printf("\n");
                }
                break;
            }
            case 5:
            {
                if(count==0)
                    printf("Array is empty. Cant enter data.\n");
                else{
                    deletion();
                }
                break;
            }
            case 6:
                exit(0);
            }
        }
    }
    return 0;
}