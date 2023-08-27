#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int );
    for(int i=0; i<n ; i++)
    {
        printf("%d | ",arr[i]);
    }
    printf("\n");
    for(int i=1; i<n ;i++)
    {
        int elmt= arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>elmt)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=elmt;
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