#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:

    double time(const vector<int>& dist, int speed) 
    {
        double time_total = 0.0;
        for (int i = 0; i < dist.size() - 1; i++) 
        {
            time_total += ceil(static_cast<double>(dist[i]) / speed);
        }
        time_total += static_cast<double>(dist.back()) / speed;
        return time_total;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        
        int n = dist.size();
        if (n > floor(hour) + 1) return -1;
        int left = 1;
        int right = 10000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            double time_total = time(dist, mid);
            if (time_total > hour) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        double last_time = time(dist, left);
        return (last_time <= hour) ? left : -1;
    }
    
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int calcAvg(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int ls = calcAvg(root->left, ans);
        int rs = calcAvg(root->right, ans);
        int cs = root->val + ls + rs;
        int count = 1;
        int avg = cs / count;
        ans += avg;
        return cs;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        calcAvg(root, ans);
        return ans;
    }
};
