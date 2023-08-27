#include <string>
#include <set>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        int count[10];
        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] == 'z') count[0]++;
            if(s[i] == 'g') count[8]++;
            if(s[i] == 'x') count[6]++;
            if(s[i] == 'w') count[2]++;
            if(s[i] == 'u') count[4]++;
            if(s[i] == 'o') count[1]++;
            if(s[i] == 'h') count[3]++;
            if(s[i] == 's') count[7]++;
            if(s[i] == 'f') count[5]++;
        }
        count[1] += -1*( count[0] + count[2] + count[4]);
        count[3] += -1*( count[8]);
        count[5] += -1*( count[4]);
        count[7] += -1*( count[6]);
        count[9] += -1*( count[5] + count[6] + count[8]);
        string ans;
        for(int i = 0; i <= 9; i++) 
        {
            while(count[i] > 0) {
                ans += to_string(i);
                count[i]--;
            }
        }
        
        return ans;
    }
};
