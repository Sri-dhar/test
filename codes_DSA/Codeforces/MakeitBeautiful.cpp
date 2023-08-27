// #include<bits/stdc++.h>
// using namespace std;
// #define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// bool compareDescending(int a, int b) {
//     return a > b;
// }

// void solve()
// {
//     int size;
//     cin>>size;
//     vector<int> arr;
//     int sum = 0;
//     for(int i =0; i<size ; i++)
//     {
//         int temp;
//         cin>>temp;
//         arr.push_back(temp);
//     }
//     int flagg=0;
//     for(int i =0; i< size-1; i++)
//     {
//         if(arr[i] != arr[i+1]) {
//         ++flagg;
//         std::cout<<"NO"<< std::endl;
//         break;
//         }
//     }
//     int flag=0;
//     if(!flagg){
//     for(int i = 0 ;i<size; i++)
//     {
//         if(i == 1)
//         {
//             if(arr[i] == arr[i-1]) std::cout<<"NO"<< std::endl;
//             flag =1;
//         }
//         else if(i>1)
//         {
//             if(arr[i] == sum) std::cout<<"NO"<< std::endl;
//             flag =1;
//         }
//         else{
//             std::cout<<"YES"<<std::endl;
//         }
//         sum+= arr[i];
//     }}
//     if(flag || flagg){
//     for(int i =0; i<size; i++)
//     {
//         std::cout<<arr[i]<<" ";
//     }
//     cout<<endl; 
//     vector<int> arrcpy = arr;
//     sort(arrcpy.begin(), arrcpy.end(), compareDescending);
//     while(arr[0] == arr[1] ){
//         int tempo{arr[0]};
//         reverse(arr.begin(),arr.end());
//         arr.pop_back();
//         reverse(arr.begin(),arr.end());
//         arr.push_back(tempo);
//     }
//     for(int i =0; i<size; i++)
//     {
//         std::cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     }
// }

// int main()
// {
//     IOS // Uncomment this line if you want to use fast I/O

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }   
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a[0] == a[n - 1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a[n - 1] << " ";
            for (int i = 0; i < n - 1; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
