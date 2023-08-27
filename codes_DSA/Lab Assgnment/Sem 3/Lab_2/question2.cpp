#include<bits/stdc++.h>
using namespace std;

int BS(vector<int>& arr, int target) {
    
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int BSalpha(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) 
    {
        int mid = left + (right - left) * 2 / 3;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

int BSbeta(vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size()-1;
    while( left <= right)
    {
        int mid = left + (right - left)/4;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main()
{
    cout<<"Enter the size of the array : ";
    int n =0;
    cin>>n;
    cout<<"Enter the sorted array : ";
    vector<int> arr (n,0);
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    cout<< "Enter the target for Binary Search : ";
    int target{};
    cin>>target;

    cout<<"The index of target thru Normal Binary Search is : "<< BS(arr,target) <<endl;
    cout<<"The index of target thru Alpha Binary Search is : "<< BSalpha(arr,target) <<endl;
    cout<<"The index of target thru Beta Binary Search is : "<< BSbeta(arr,target) <<endl;
    return 0;
}
