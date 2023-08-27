#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int temp = num;
        vector<string> ans;
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for (int i = 0; i < values.size(); i++) {
            while (temp >= values[i]) {
                ans.push_back(symbols[i]);
                temp -= values[i];
            }
        }
        
        string str;
        for (const string& s : ans) {
            str += s;
        }
        return str;
    }
};

int main() {
    Solution solution;
    for (int num = 1; num <= 3999; num++) {
        string roman = solution.intToRoman(num);
        cout << num << ": " << roman << endl;
    }
    return 0;
}
