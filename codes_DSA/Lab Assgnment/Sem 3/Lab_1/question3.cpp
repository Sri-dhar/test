#include <iostream>
#include<vector>
using namespace std;

string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] = ans[i + j + 1] % 10;
            }
        }

        string str;
        for (int digit : ans) {
            str += (digit + '0');
        }
        
        int i = 0;
        while (i < str.length() && str[i] == '0') i++;
        if (i == str.length())
        return "0";
        return str.substr(i);
    }

int main() {
    cout << "Enter the first number: ";
    string str1= "";
    cin >> str1;

    cout << "Enter the second number: ";
    string str2= "";
    cin >> str2;

    string ans = multiply(str1,str2);
    cout<<ans<<endl;
    
    return 0;
}