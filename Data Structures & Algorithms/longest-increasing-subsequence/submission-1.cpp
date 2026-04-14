class Solution {
public:
    int calculateLIS(vector<int>& nums, vector<vector<int>>& dp, int i, int lastIdx) {
        if(i==nums.size()) return 0;
        if(dp[i][lastIdx+1]) return dp[i][lastIdx+1];

        if(lastIdx == -1 || nums[lastIdx] < nums[i]){
            return dp[i][lastIdx+1] = max(1 + calculateLIS(nums, dp, i+1, i), calculateLIS(nums, dp, i+1, lastIdx));
        } else {
            return dp[i][lastIdx+1] = calculateLIS(nums, dp, i+1, lastIdx);
        }
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, 0));
        return calculateLIS(nums, dp, 0, -1);
    }
};
