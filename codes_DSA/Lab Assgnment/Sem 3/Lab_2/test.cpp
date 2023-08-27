class Solution {
public:
    bool isNumber(string s) {
        bool hasSign = true, hasDot = false, hasE = false, hasDigit = false;
        
        for (char c : s) {
            if ((c == '-' || c == '+') && hasSign) {
                hasSign = false;
                continue;
            }
            
            hasSign = false;
            
            if (c == '.') {
                if (!hasE && !hasDot) {
                    hasDot = true;
                } else {
                    return false;
                }
                continue;
            }
            
            if (c == 'e' || c == 'E') {
                if (!hasE && hasDigit) {
                    hasE = true;
                } else {
                    return false;
                }
                hasSign = true; 
                hasDigit = false; 
                continue;
            }
            
            if (isdigit(c)) {
                hasDigit = true;
                continue;
            }
            
            return false;
        }
        return hasDigit;
    }
};
