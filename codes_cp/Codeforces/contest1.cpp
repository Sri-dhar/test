#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main()
{
    IOS

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum=0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum+= arr[i];
        }
        int result = 1;
        if(sum%2) result =0;
        
        cout << (result ? "YES" : "NO") << endl;
    }
    return 0;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the target at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}