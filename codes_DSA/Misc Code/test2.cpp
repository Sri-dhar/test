#include<bits/stdc++.h>
using namespace std;
void f( vector<int> & arr)
{
    for(int i=0; i<arr.size(); i++){
        swap(arr[i],arr[i+1]);
        i++;
    }
}
int main()
{
    vector<int> arr {1,34,345,34,23,23};
    for(auto i: arr) cout<<i<<"  ";
    cout<<endl;
    f(arr);
    for(auto i: arr) cout<<i<<"  ";
    cout<<endl;
}