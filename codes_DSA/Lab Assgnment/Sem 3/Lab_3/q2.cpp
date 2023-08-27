#include<iostream>

void DNC(int n, int arr[], int& ans, int first, int last)
{
    if (first > last) return;
    int mid = ( first + last )/2;

    if (arr[mid] == mid + 1) DNC(n, arr, ans, mid + 1 , last );
    else 
    {
        ans = mid + 1;
        DNC(n, arr, ans, first, mid - 1);
    }
}

int main()
{
    std::cout << "Enter the size of the array: ";
    int n;
    std::cin >> n;
    int* arr = new int[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
        
    int ans = -1;

    DNC(n, arr, ans, 0, n - 1);
    std::cout << "\nThe missing number is " << ans;

    return 0;
}
