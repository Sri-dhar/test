#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>

#define ll long long int
ll res = 1;
ll prevNoOfPositions = 0;
ll gc=0;

ll fact(ll n)
{
    ll ans = 1;
    for(int i=1; i<=n ; i++) ans *= i;
    return ans;
}

ll c(ll n, ll r)
{
    return fact(n)/(fact(n-r)*fact(r));
}

// void ff(int n , int count , int noOfPositions)
// {
//     if(count == n) 
//     {
//         res ++;
//         return ;
//     }
//     for(int i=0; i<noOfPositions ; i++)
//     {   
//         prevNoOfPositions = noOfPositions;
//         ff(n , count+1, noOfPositions*2+1);
//     }
// }

int sumofarr(std::vector<int> arr)
{
    int sum = 0;
    for(auto i:arr) sum+= i;
    return sum;
}

std::vector<int> arr;
ll ans =0;
void f(int n, int count, int n_counter)
{   
    if(sumofarr(arr) == n) //array is filled with positions
    {   
        ans++ ;
        return;
    }
    for(int i=0; i<=arr.size(); i++)
    {
        if(i < arr.size())
        {
            for(int j=0; j<arr.size(); j++)
            {
                arr[i]++;
                f(n, count, n_counter + 1);
                arr[i]--; -
                
            }
        }
        else
        {
            arr.push_back(1);
            f(n, count + 1, n_counter + 1);
            arr.pop_back();
        }   
    }
}

int main()
{
    std::cout<<"Enter the value of n :"<<std::endl;
    int n{};
    std::cin>>n;
    std::cout<<"The number of outcomes possible when ties are not allowed are : "<<fact(n)<<std::endl;
    f(n,0,0);
    std::cout<<"The number of outcomes possible when ties are allowed are : "<<ans<<std::endl;
}