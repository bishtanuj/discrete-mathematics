#include<stdio.h>
#define maxsize 100
int main()
{
    int Set[maxsize],num;
    int temp = 0,temp_1 = 0;
    
    printf("*******************************************\n");
    printf("Enter the set having maximum four elements\n");
    printf("*******************************************\n");
    printf("\n");
    
    //Scanning the cardinal number of set
    printf("Enter the cardinal number of set: ");
    scanf("%d",&num);

    if(num > 0 && num < 5)
    {
        // Scanning the elements of Set
        printf("Enter the %d elements of set: \n",num);
        for(int i=0; i<num; i++)
        {
            printf("Element [%d]: ",i+1);
            scanf("%d",&Set[i]);
        }
    
        // Printing the Set taken by user
        printf("\n");
        printf("Set: \n");
        printf("{ ");
        for(int i=0; i<num-1; i++)
        {
            printf("%d, ",Set[i]);
            temp++;
        }
        printf("%d ",Set[temp]);
        printf("}");
    }
    
    // Printing the power set
    if(num < 5)
    {
        printf("\n\n");
        printf("Power Set: \n");
        printf("{");
        switch(num)
        {
            // If the cardinal number is 0
            case 0:
            {
                printf("{}");
                break;
            }

            // If the cardinal number is 1
            case 1:
            {
                printf("{}, ");
                for(int i=0; i<num; i++)
                {
                    printf("{%d}",Set[i]);
                }
                break;
            }
        
            // If the cardinal number is 2
            case 2:
            {
                printf("{}, ");

                for(int i=0; i<num; i++)
                {
                    printf("{%d}, ",Set[i]);
                }
       
                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num; j++)
                    {
                        printf("{%d, %d}",Set[i],Set[j]);
                    }
                }
            
                break;
            }
        
            // If the cardinal number is 3
            case 3:
            {
                printf("{}, ");  

                for(int i=0; i<num; i++)
                {
                    printf("{%d}, ",Set[i]);
                }

                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num; j++)
                    {
                        printf("{%d, %d}, ",Set[i],Set[j]);
                    }
                }

                printf("{");
                for(int i=0; i<num-1; i++)
                {
                    printf("%d, ",Set[i]);
                    temp_1++;
                }
                printf("%d",Set[temp_1]);
                printf("}");
            
                break;
            }
        
            // If the cardinal number is 4
            case 4:
            {
                printf("{}, ");  

                for(int i=0; i<num; i++)
                {
                    printf("{%d}, ",Set[i]);
                }

                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num; j++)
                    {
                        printf("{%d, %d}, ",Set[i],Set[j]);
                    }
                }
            
                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num; j++)
                    {
                        for(int k=j+1; k<num; k++)
                        {
                            printf("{%d, %d, %d}, ",Set[i],Set[j],Set[k]);
                        }
                    }
                }

                printf("{");
                for(int i=0; i<num-1; i++)
                {
                    printf("%d, ",Set[i]);
                    temp_1++;
                }
                printf("%d",Set[temp_1]);
                printf("}");
            
                break;
            }
        }
        printf("}");
    }

    // If the cardinal number is greater than 4
    if(num > 4)
    {
        printf("Do enter maximum cardinal number = 4");
    }

    return 0;
}
