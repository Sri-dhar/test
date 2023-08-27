#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// int maxProductSubarray(std::vector<int>& nums, int left, int right) {
//     if (left == right) return nums[left];

//     int mid = (left+right) /2;
//     int leftMax = maxProductSubarray(nums, left, mid);
//     int rightMax = maxProductSubarray(nums, mid + 1, right);

//     int leftProd = 1;
//     int rightProd = 1;
//     int maxLeftProd = INT_MIN;
//     int maxRightProd = INT_MIN;

//     for (int i = mid; i >= left; i--) 
//     {
//         leftProd *= nums[i];
//         maxLeftProd = std::max(maxLeftProd, leftProd);
//     }

//     for (int i = mid + 1; i <= right; i++) 
//     {
//         rightProd *= nums[i];
//         maxRightProd = std::max(maxRightProd, rightProd);
//     }

//     int maxi = maxLeftProd * maxRightProd;
//     return std::max(leftMax, std::max(rightMax, maxi));
// }

// int maxProduct(std::vector<int>& nums) {
//     int n = nums.size();
//     if (n == 0) {
//         return 0;
//     }

//     return maxProductSubarray(nums, 0, n - 1);
// }


    int maximumCrossProduct(vector<int> &nums, int l, int m, int r) {
        int maxLeft = INT_MIN;
        int minleft = INT_MAX;
        int prod = 1;
        
        for(int i = m; i >= l; i--) {
            prod = prod * nums[i];
            maxLeft = max(maxLeft, prod);
            minleft = min(minleft, prod);
        }

        int maxRight = INT_MIN;
        int minRight = INT_MAX;
        prod = 1;

        for(int i = m + 1; i <= r; i++) {
            prod = prod * nums[i];

            maxRight = max(maxRight, prod);
            minRight = min(minRight, prod);
        }

        int mx = maxLeft * maxRight;
        int mi = minleft * minRight;

        return max(mx, mi);
    }

    int maximumProduct(vector<int> &nums, int l, int r) {
        if(l >= r) {
            return nums[l];
        }

        int m = l + (r - l) / 2;
        int left = maximumProduct(nums, l, m);
        int right = maximumProduct(nums, m + 1, r);
        int midProd = maximumCrossProduct(nums, l, m, r);

        return max(max(left, right), midProd);
    }

    int maxProduct(vector<int>& nums) {
        return maximumProduct(nums, 0, nums.size() - 1);        
    }


int main() {
    std::cout << "Enter the size of the array: ";
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = maxProduct(arr);
    std::cout << "The largest product is : " << result << std::endl;

    return 0;
}
