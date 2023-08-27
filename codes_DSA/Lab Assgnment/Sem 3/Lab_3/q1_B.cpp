#include <iostream>
#include <algorithm>

void DNC(int arr[], int left, int right , int ans[2]) 
{
    if (left == right) {
        ans[0] = arr[left];
        ans[1] = arr[right];
        return;
    }

    int mid = (left + right) / 2;
    int mini, maxi, minii, maxii;
    DNC(arr, left, mid, ans); 
    mini = ans[0];
    maxi = ans[1];

    DNC(arr, mid + 1, right , ans);
    minii = ans[0];
    maxii = ans[1];
    
    ans[0] = std::min(mini, minii);
    ans[1] = std::max(maxi, maxii);
}



int main() {
    std::cout << "Enter the size of the array: ";
    int n;
    std::cin >> n;
    int* arr = new int[n];
    int ans[2] = {0};

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    DNC(arr, 0, n - 1, ans);
    std::cout << "The maximum element in the array is: " << ans[1] << std::endl;
    std::cout << "The minimum element in the array is: " << ans[0] << std::endl;

    return 0;
}
