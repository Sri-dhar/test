#include<bits/stdc++.h>
int ans{};  

void medofmed(std::vector<int> &arr)
{
    if(arr.size() <= 5) {
        std::sort(arr.begin(), arr.end());
        ans = arr[arr.size() / 2];
        return ;
    }

    int n = arr.size();
    int i{};
    int divisions = (n % 5 != 0) ? n / 5 + 1 : n / 5 ;

    for(i = 0; i < divisions-1; i++) std::sort(arr.begin() + i * 5, arr.begin() + (i + 1) * 5);
    std::sort(arr.begin()+5*i, arr.begin()+5*i+n%5);

    std::vector<int> arr2;
    for(int i=2; i<n; i+= 5) arr2.push_back(arr[i]);

    medofmed(arr2);

}



int main()
{
    std::cout<<"Enter the array elements: "<<std::endl;
    std::cout<<"Enter -1 to stop"<<std::endl;

    std::vector<int> arr;
    int temp;
    while(true)
    {
        std::cin>>temp;
        if(temp == -1) break;
        arr.push_back(temp);
    }

    int k ;
    std::cout<<"Enter the value of K";
    std::cin>> k;

    int ans = KthSmallest(arr ,0 ,n-1 ,k);
}