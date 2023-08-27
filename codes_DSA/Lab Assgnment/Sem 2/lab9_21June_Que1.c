#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

int comparator(const void *p, const void *q) 
{ 
      return (*(int*)p-*(int*)q);
}
int main()
{
    printf("Enter the size of the array : ");
    int size=0;
    scanf("%d",&size);
    printf("\nEnter the array : ");
    int *arr=(int*)malloc(sizeof(int)*size);
    for(int i=0; i<size ; i++)
    {
        scanf("%d",arr+i);
    }
    
    qsort((void*)arr, size, sizeof(arr[0]), comparator);
    int * unique_elmts = (int*) calloc( MAXSIZE ,sizeof(int));
    
    for(int i=0; i<MAXSIZE ; i++)
    {
        unique_elmts[i] = 1;
    }
    
    for(int i=0; i<size ; i++)
    {
        if(arr[i]==arr[i+1])
        unique_elmts[arr[i]]++;
    }
    printf("The sorted array is : ");
    for(int i=0; i<size ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("\n");
    for(int i=0; i< MAXSIZE ; i++)
    {
        if(unique_elmts[i]!= 1)
        {
            printf("%d has occured %d times. \n",i,unique_elmts[i]);
        }
    }

    return 0;
}
