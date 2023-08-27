#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, vector<int>& arr4) {
    vector<int> ans;
    int i = 0, j = 0, k = 0, l = 0;

    while (i < arr1.size() || j < arr2.size() || k < arr3.size() || l < arr4.size()) 
    {
        int mini = INT_MAX;

        if (i < arr1.size()) mini = min(mini, arr1[i]);
        if (j < arr2.size()) mini = min(mini, arr2[j]);
        if (k < arr3.size()) mini = min(mini, arr3[k]);
        if (l < arr4.size()) mini = min(mini, arr4[l]);

        ans.push_back(mini);

        if (i < arr1.size() && arr1[i] == mini) i++;
        else if (j < arr2.size() && arr2[j] == mini) j++;
        else if (k < arr3.size() && arr3[k] == mini) k++;
        else l++;
    }

    return ans;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> first_half(arr.begin(), arr.begin() + mid);
    vector<int> second_half(arr.begin() + mid, arr.end());

    int mid1 = first_half.size() / 2;
    int mid2 = second_half.size() / 2;

    vector<int> arr1(first_half.begin(), first_half.begin() + mid1);
    vector<int> arr2(first_half.begin() + mid1, first_half.end());
    vector<int> arr3(second_half.begin(), second_half.begin() + mid2);
    vector<int> arr4(second_half.begin() + mid2, second_half.end());

    arr1 = mergeSort(arr1);
    arr2 = mergeSort(arr2);
    arr3 = mergeSort(arr3);
    arr4 = mergeSort(arr4);

    return merge(arr1, arr2, arr3, arr4);
}

int main()
{
    cout << "Enter the size of the array : ";
    int n = 0;
    cin >> n;
    cout << "Enter the array : ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    arr = mergeSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
