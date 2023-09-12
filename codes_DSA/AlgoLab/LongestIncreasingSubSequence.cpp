#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<climits>

using namespace std;

int LISrec(vector<int> arr ,int i, int j )
{
    if(i == arr.size()) return 0;
    int len { LISrec(arr,i+1,j) };
    if(j == -1 or arr[i]> arr[j])
        len = max(len , 1+LISrec(arr,i+1,i));
    return len;
}

int LISrecMemo(vector<int> arr, int i, int j, vector<vector<int>>& memo)
{
    if(i == arr.size()) return 0;
    if(memo[i][j+1] != INT_MIN) return memo[i][j];
    int len { LISrecMemo(arr, i + 1, j, memo) };
    if(j == -1 or arr[i] > arr[j])
        len = max(len , 1 + LISrecMemo(arr, i + 1, i, memo));
    return memo[i][j+1] = len;
}

int main()
{
    std::cout << "Enter the array : " << std::endl;
    std::cout << "Enter -1 to stop" << std::endl;
    std::vector<int> arr;
    int temp{};
    while (1)
    {
        std::cin >> temp;
        if (temp == -1) break;
        arr.push_back(temp);
    }

    int ans1 = LISrec(arr,0,-1);
    std::cout<<"LIS_rec : "<<ans1<<std::endl;

    vector<vector<int>> memo (arr.size()+1, vector<int>(arr.size()+1,INT_MIN));
    int ans2 = LISrecMemo(arr,0,-1,memo);
    std::cout<<"Lis_rec_memo : "<<ans2<<std::endl;
    return 0;
}