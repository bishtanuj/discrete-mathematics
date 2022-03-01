#include<stdio.h>
#define maxsize 100
int main()
{
    int Set[maxsize],num;
    int temp = 0;
    int Matrix[maxsize][maxsize];

    //Scanning the elements of set
    printf("Enter the number of elements of set: ");
    scanf("%d",&num);

    //Scanning the elements of set
    printf("\n\nEnter the elements of set: \n");
    for(int i=0; i<num; i++)
    {
        printf("Element [%d]: ",i+1);
        scanf("%d",&Set[i]);
    }

    //Printing the set
    printf("\n\nSet:\n");
    printf("{ ");
    for(int i=0; i<num-1; i++)
    {
        printf("%d, ",Set[i]);
        temp++;
    }
    printf("%d ",Set[temp]);
    printf("}");

    //Printing the relation
    printf("\n\nThe Relation: \n");
    printf("{ ");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if((Set[i] + Set[j])%3 == 0)
            {
                printf("(%d,%d) ",Set[i],Set[j]);
            }
        }
    }
    printf("}");

    //Making of matrix
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if((Set[i] + Set[j])%3 == 0)
            {
                Matrix[i][j] = 1;
            }
            else
            {
                Matrix[i][j] = 0;
            }
        }
    }

    //Printing the matrix
    printf("\n\nThe Matrix: \n");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }

    //Applying Warshall method
    for(int k=0; k<num; k++)
    {
        for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                Matrix[i][j] = (Matrix[i][j] || Matrix[i][k] && Matrix[k][j]);
            }
        }
    }

    //Printing the Warshall Matrix
    printf("\n\nMatrix after applying Warshall method: \n");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
    
    // Printing relation after applying Warshall algorithm
    printf("\n");
    printf("Relation after applying Warshall algorithm: \n");
    printf("{ ");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(Matrix[i][j] == 1)
            {
                printf("(%d, %d) ",i+1,j+1);
            }
        }
    }
    printf("}");
    return 0;
}
