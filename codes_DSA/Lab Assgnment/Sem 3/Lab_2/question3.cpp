#include<bits/stdc++.h>
using namespace std;

int TS(vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right)
    {
        int lowmid = left + (right - left) / 3;
        int highmid = left + (right - left) * 2 / 3;
        
        if (arr[lowmid] == target) return lowmid;
        if (arr[highmid] == target) return highmid;       
        if (arr[lowmid] > target) right = lowmid - 1;
        else if (arr[highmid] < target) left = highmid + 1;
        else
        {
            left = lowmid + 1;
            right = highmid - 1;
        }
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
    cout<< "Enter the target for Ternary Search : ";
    int target{};
    cin>>target;
    cout<<"The index of target thru Ternary Search is : "<< TS(arr,target) <<endl;
    return 0;
}
