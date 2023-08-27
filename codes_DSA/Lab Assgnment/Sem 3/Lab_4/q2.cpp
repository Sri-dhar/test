#include<bits/stdc++.h>

int counter(std::vector<int>& arr, int num, int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) if (arr[i] == num) count++;
    return count;
}

int FindMajor(std::vector<int> arr, int low , int high)
{
    if(low == high) return arr[low];
    int mid = low + (high - low)/2;
    int lMajor = FindMajor(arr,low,mid);
    int rMajor = FindMajor(arr,mid+1,high);
    if(counter(arr,lMajor,low,mid-1) > (high-low+1)/2) return counter(arr,lMajor,low,high);
    else if(counter(arr,rMajor,mid+1,high) > ((high-low+1)/2)) return counter(arr,rMajor,low,high);
    else return -1;
}

int main() {
    std::cout << "Enter the size of the array: ";
    int n{};
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout<<"Enter the array : "<<std::endl;
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    int majority = FindMajor(arr, 0, n - 1);
    std::cout << "The majority element is ";
    if (majority != -1) std::cout << majority << std::endl;
    else std::cout << "not present" << std::endl;
    return 0;
}