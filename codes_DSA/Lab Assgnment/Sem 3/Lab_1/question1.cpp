#include<iostream> 
#include<vector>
using namespace std;

int evaluate(vector<char> oper, vector<int> opera) {

    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == '*') {
            opera[i] = opera[i] * opera[i + 1];
            opera.erase(opera.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i--;
        } else if (oper[i] == '/') {
            opera[i] = opera[i] / opera[i + 1];
            opera.erase(opera.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i--; 
        }
    }
    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == '+') {
            opera[i] = opera[i] + opera[i + 1];
            opera.erase(opera.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i--; 
        } else if (oper[i] == '-') {
            opera[i] = opera[i] - opera[i + 1];
            opera.erase(opera.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i--; 
        }
    }

    return opera[0];
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '*' || ch == '/' || ch == '-');
}

int main() {
    cout << "Enter the infix expression : " << std::endl;
    string str = "";
    cin >> str;
    vector<char> oper;
    vector<int> opera;
    for (int i = 0; i < str.size(); i++) {
        if (isOperator(str[i]))
            oper.push_back(str[i]);
        else {
            int temp = 0;
            int tempidx = i;
            while (tempidx < str.size() && !isOperator(str[tempidx])) {
                temp *= 10;
                temp += str[tempidx] - '0';
                tempidx++;
            }
            opera.push_back(temp);
            i = tempidx - 1; 
        }
    }
    cout << "The output is : " << evaluate(oper, opera) << endl;
    return 0;
}
