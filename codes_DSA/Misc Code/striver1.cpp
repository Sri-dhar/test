#include<iostream>

int main()
{
    std::cout<<"Enter the no of elements in the array"<<std::endl;
    int n=0;
    std::cin>>n;
    
    int* arr = new int[n]; // Dynamic memory allocation
    
    for(int i=0; i<n ; i++)
    {
        std::cin>>arr[i];
    }
    
    std::cout<<"The elements you entered are : ";
    for(int i=0; i<n ; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    
    std::cout<<"\nThe modified array now is : ";
    for(int i=0; i<n ; i++)
    {
        if(arr[i] < 0)
        {
            std::cout<<arr[i]<<" ";
        }
    }
    for(int i=0; i<n ; i++)
    {
        if(arr[i] >= 0)
        {
            std::cout<<arr[i]<<" ";
        }
    }
    
    delete[] arr; // Deallocate the dynamically allocated memory
    
    std::cin.get();
}
