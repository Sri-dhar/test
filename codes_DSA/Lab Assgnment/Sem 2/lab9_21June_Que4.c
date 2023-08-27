#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter the number of icecreams available : ");
    int size=0;
    scanf("%d",&size);
    printf("\nEnter the amount of the icecream one by one: ");
    int *arr=(int*)malloc(sizeof(int)*size);
    for(int i=0; i<size ; i++)
    {
        scanf("%d",arr+i);
    }
    printf("\n");
    printf("Enter the total amount of money you have : ");
    int money=0;
    scanf("%d",&money);
    printf("\n\n");
   for(int i=0;i<size;i++)
    {
        for(int j=0; j<size; j++)
        {
            if(arr[j]+arr[i]==money)
            {
                printf("You can buy icecream priced %d and %d together\n", arr[j], arr[i]);
                printf("Their indexes are %d and %d\n\n",i,j);
            }
        }
    }
    return 0;

}

