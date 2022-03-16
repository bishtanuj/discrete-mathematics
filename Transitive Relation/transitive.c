#include<stdio.h>
int main()
{
    int Set[10],num,temp = 0,count = 1;
    int Matrix[10][10],Matrix_1[10][10],Matrix_2[10][10];

    //Scanning the number of elements of set A
    printf("Enter the number of elements of set A: ");
    scanf("%d",&num);

    //Scanning the elements of set A
    printf("Enter the elements of set A: ");
    for(int i=0; i<num; i++)
    {
        scanf("%d",&Set[i]);
    }

    //Printing the Set A
    printf("\n");
    printf("Set: \n");
    printf("A = ");
    printf("{ ");
    for(int i=0; i<num-1; i++)
    {
        printf("%d, ",Set[i]);
        temp++;
    }
    printf("%d ",Set[temp]);
    printf("}");

    //Printing the relation on set A
    printf("\n\n");
    printf("The relation: \n");
    printf("{ ");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if((Set[i] + Set[j]) % 3 == 0)
            {
                printf("(%d, %d) ",Set[i],Set[j]);
            }
        }
    }
    printf("}");

    //Creating the matrix of the relation
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if((Set[i] + Set[j]) % 3 == 0)
            {
                Matrix[i][j] = 1;
            }
            else
            {
                Matrix[i][j] = 0;
            }
        }
    }

    //Printing the matrix made up of relation
    printf("\n\n");
    printf("Matrix: \n");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }

    //Multiplication of Matrix 
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            Matrix_1[i][j] = 0;
            for(int k=0; k<num; k++)
            {
                Matrix_1[i][j] = Matrix_1[i][j] + Matrix[k][j] * Matrix[i][k];
            }
        }
    }

    //Converting non zero elements of Matrix_1 to 1
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(Matrix_1[i][j] != 0)
            {
                Matrix_1[i][j] = 1;
            }
        }
    }

    //Printing Matrix_1
    printf("\n\n");
    printf("The square of Matrix: \n");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ",Matrix_1[i][j]);
        }
        printf("\n");
    }

    //Addition of Matrix and Matrix_1
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            Matrix_2[i][j] = Matrix_1[i][j] + Matrix[i][j];
        }
    }

    //Converting non zero elements of Matrix_2 to 1
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(Matrix_2[i][j] != 0)
            {
                Matrix_2[i][j] = 1;
            }
        }
    }

    //Printing Matrix_2
    printf("\n\n");
    printf("Sum of Matrix and Square of Matrix: \n");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ",Matrix_2[i][j]);
        }
        printf("\n");
    }

    //Checking for the relation is transitive or not
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(Matrix_2[i][j] != Matrix[i][j])
            {
                count = 0;
                break;
            }
        }
        if(count == 0)
        {
            break;
        }
    }

    //Printing the decision
    if(count == 0)
    {
        printf("Relation is not transitive");
    }
    else
    {
        printf("Transitive Relation");
    }
    return 0;
}
