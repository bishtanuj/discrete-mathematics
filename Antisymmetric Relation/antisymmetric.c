#include<stdio.h>
#define maxSize 100

int main()
{
    int set[maxSize], setSize;
    int temp = 0, count = 0;
    int matrix[maxSize][maxSize];

    // Scanning the size of the set
    printf("Enter the size of the set: ");
    scanf("%d",&setSize);

    // Scanning the elements of set
    printf("Enter the elements of set: \n");
    for(int i=0; i<setSize; i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",&set[i]);
    }

    // Printing the set
    printf("Set: \n");
    printf("{");
    for(int i=0; i<setSize-1; i++)
    {
        printf("%d, ",set[i]);
        temp++;
    }
    printf("%d",set[temp]);
    printf("}");

    // Printing the relation
    printf("\n");
    printf("Relation: \n");
    printf("{ ");
    for(int i=0; i<setSize; i++)
    {
        for(int j=0; j<setSize; j++)
        {
            if((set[i] + set[j]) %3 == 0)
            {
                printf("(%d,%d) ",set[i],set[j]);
            }
        }
    }
    printf("}");

    // Creating a matrix
    for(int i=0; i<setSize; i++)
    {
        for(int j=0; j<setSize; j++)
        {
            if((set[i] + set[j]) %3 == 0)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Printing the matrix
    printf("\n");
    printf("Matrix: \n");
    for(int i=0; i<setSize; i++)
    {
        for(int j=0; j<setSize; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    // Computing the anti symmetric relation
    for(int i=0; i<setSize; i++)
    {
        for(int j=0; j<setSize; j++)
        {
            if(matrix[i][j] == matrix[j][i] && matrix[i][j] == 1)
            {
                count = 1;
            }
        }
    }

    // Printing the conclusion
    if(count == 0)
    {
        printf("\nThe relation is an Anti-symmetric.");
    }
    else
    {
        printf("\nThe relation is not an Anti-symmetric.");
    }

    return 0;
}
