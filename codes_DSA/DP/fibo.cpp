#include <iostream>
#include <vector>
#include<climits>
using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, vector<int>& arr4) {
    vector<int> ans;
    int i = 0, j = 0, k = 0, l = 0;

    while (i < arr1.size() || j < arr2.size() || k < arr3.size() || l < arr4.size()) {
        int mini = INT_MAX;

        if (i < arr1.size()) mini = min(mini, arr1[i]);
        if (j < arr2.size()) mini = min(mini, arr2[j]);
        if (k < arr3.size()) mini = min(mini, arr3[k]);
        if (l < arr4.size()) mini = min(mini, arr4[l]);

        ans.push_back(mini);

        if (i < arr1.size() && arr1[i] == mini) i++;
        else if (j < arr2.size() && arr2[j] == mini) j++;
        else if (k < arr3.size() && arr3[k] == mini) k++;
        