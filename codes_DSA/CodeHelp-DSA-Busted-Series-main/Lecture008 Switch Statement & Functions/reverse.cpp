#include<iostream>
int main()
{
    std::cout<<"Enter the number of elements of the array"<<std::endl;
    int n{0};
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter the elements of the array"<<std::endl;
    
    for(int i=0; i<n ; i++)
    {
        std::cin>>arr[i];
    }
    
    for(int i=0; i< (n/2) ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    
    for(int i=0 ; i<n ; i++)
    {
        std::cout<< arr[i]<<" " ;
    }
    return 0;
}
