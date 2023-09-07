#include <iostream>
#include <vector>
#include <algorithm>

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

// int medofmed(std::vector<int> &arr) {
//     if (arr.size() <= 5) {
//         std::sort(arr.begin(), arr.end());
//         return arr[arr.size() / 2];
//     }

//     int n = arr.size();
//     int divisions = (n % 5 != 0) ? n / 5 + 1 : n / 5;
//     std::vector<int> medians(divisions);

//     for (int i = 0; i < divisions; i++) {
//         std::vector<int>::iterator begin = arr.begin() + i * 5;
//         std::vector<int>::iterator end = (i == divisions - 1) ? arr.end() : begin + 5;
//         std::sort(begin, end);
//         medians[i] = *(begin + (end - begin) / 2);
//     }

//     int median_of_medians = medofmed(medians);
//     std::vector<int> arr1, arr2, arr3;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] < median_of_medians) {
//             arr1.push_back(arr[i]);
//         } else if (arr[i] == median_of_medians) {
//             arr2.push_back(arr[i]);
//         } else {
//             arr3.push_back(arr[i]);
//         }
//     }

//     if (arr1.size() > arr2.size()) {
//         return medofmed(arr1);
//     } else if (arr1.size() + arr2.size() > (n + 1) / 2) {
//         return median_of_medians;
//     } else {
//         return medofmed(arr3);
//     }
// }



int main()
{
    std::cout << "Enter the array elements" << std::endl;
    std::cout << "Enter -1 to stop :";
    std::vector<int> arr;
    while(1)
    {
        int temp ; 
        std::cin >> temp; 
        if(temp != -1) arr.push_back(temp);
        else 
        {
            break;
        }
    }
    std::vector<int>arr2 = arr;
    sort(arr2.begin(),arr2.end());

    for(int i =0 ;i<arr2.size(); i++) std::cout<<arr2[i]<<" ";
    std::cout<<std::endl;

    std::cout<<"The accurate median is : "<<arr2[arr2.size()/2]<<std::endl;
    std::cout << "The approximate median is: ";
    medofmed(arr);
    std::cout << " "<<ans<<std::endl;
    return 0;
}
