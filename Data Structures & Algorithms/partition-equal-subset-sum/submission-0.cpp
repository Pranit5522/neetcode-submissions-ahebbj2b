class Solution {
public:
    int calc(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(target < 0) return false;
        if(i == nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = calc(nums, target - nums[i], i+1, dp) || calc(nums, target, i+1, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += num;
        }

        if(sum%2) return false;

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return calc(nums, target, 0, dp);
    }
};
