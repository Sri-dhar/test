#include<iostream>
#include<bits/stdc++.h>

void printF(int ind, std::vector<int> &ds , int arr[] ,int n)
{
    if(ind ==n)
    {
        for(auto it:ds)
        {
            std::cout<<it<<" ";
        }
        if(ds.size()==0) std::cout<<"{} ";
        std::cout<<std::endl;
        return ;
    }
    ds.push_back(arr[ind]);
    printF(ind+1, ds , arr , n);
    ds.pop_back();

    printF(ind+1, ds , arr , n);
}

int main()
{
    int arr[]={3,1,2};
    int n=3;
    std::vector <int> ds;
    printF(0, ds , arr , n);
}