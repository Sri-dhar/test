#include<iostream>
int main()
{
    std::cout<<"Enter the no of elements in the array"<<std::endl;
    int n=0;
    std::cin>>n;
    int arr[n];
    for(int i=0; i<n ; i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"The elements you entered are : ";
    for(int i=0; i<n ; i++)
    {
        std::cout<<arr[i];
    }
    std::cin.get();

}