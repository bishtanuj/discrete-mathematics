#include<stdio.h>
int main()
{
    int Array_1[10],Array_2[10],Array_3[20],Array_4[20];
    int num_1,num_2,temp = 0,temp_1 = 0,temp_2,location;
    int count = 0;

    //Scanning Array_1
    printf("Enter the number of elements of Set A: ");
    scanf("%d",&num_1);
    printf("Enter the elements of Set A: ");
    for(int i=0; i<num_1; i++)
    {
        scanf("%d",&Array_1[i]);
    }

    //Scanning Array_2
    printf("Enter the number of elements of Set B: ");
    scanf("%d",&num_2);
    printf("Enter the elements of Set B: ");
    for(int j=0; j<num_2; j++)
    {
        scanf("%d",&Array_2[j]);
    }

    // Creating set of intersection
    for(int i=0; i<num_1; i++)
    {
        for(int j=0; j<num_2; j++)
        {
            if(Array_1[i] == Array_2[j])
            {
                Array_3[temp] = Array_1[j];
                temp++;
                location = temp;
            }
        }
    }

    // Creating set of Union 
    for(int i=0; i<num_1; i++)
    {
        Array_4[i] = Array_1[i];
        temp_1++;
    }

    for(int i=0; i<num_2; i++)
    {
        temp_2 = 0;
        for(int j=0; j<num_1; j++)
        {
            if(Array_2[i] == Array_1[j])
            {
                temp_2 = 1;
                break;
            }
        }

        if(temp_2 == 0)
        {
            Array_4[temp_1] = Array_2[i];
            temp_1++;
        }
    }

    // Printing the set of intersection
    printf("The Set of intersection: ");
    printf("{ ");
    for(int i=0; i<location; i++)
    {
        printf("%d ",Array_3[i]);
    }
    printf("}");

    // Printing the set of union
    printf("\n");
    printf("The set of union: ");
    printf("{ ");
    for(int j=0; j<temp_1; j++)
    {
        printf("%d ",Array_4[j]);
    }
    printf("}");
    return 0;
}
