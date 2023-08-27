#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int* b)
{
    int t=*a;
    *a = *b;
    *b=t;
}

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int );
    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr+j,arr+j+1);
        }
        // for(int i2=0; i2<n ; i2++)
        // {
        //     printf("%d | ",arr[i2]);
        // }
        // printf("\n");
    }
    for(int i=0; i<n ; i++)
    {
        printf("%d | ",arr[i]);
    }
}