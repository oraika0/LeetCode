#include <climits>
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> DP(nums.size(),INT_MAX);
        DP[0] = 0;
        for (int i = 1; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (i <= j + nums[j]){
                    DP[i] = min(DP[i], DP[j] + 1);
                }
            }
        }
        return DP[nums.size()-1];
    }
};

// DP way
// DP[i] = min (DP[j] + 1) , i > j
// DP[0] = 0