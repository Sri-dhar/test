#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"Enter the size of the array : ";
    int n{};
    cin>>n;
    cout<<"Enter the sorted array : ";
    vector<int> arr (n,0);
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    int min = arr[0];
    int max = arr[n-1];
    if(min > max) swap(min,max);
    cout<< "The min of the array is : " << min <<endl;
    cout<< "The max of the array is : " << max <<endl;
    return 0;
}