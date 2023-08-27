#include<iostream>
#include<vector>
void func(int it, std::vector<int> arr)
{
    if(it >=3)
    {
        for(int i:arr)
        {
            std::cout<<i<<"\t";
        }
        std::cout<<std::endl;
    }
    arr.push_back(arr[it]);
    func(it+1, arr);
    arr.pop_back();
    func(it+1, arr);
}

int main()
{
    std::vector <int> arr={1,2,3};
    func(0, arr);
}