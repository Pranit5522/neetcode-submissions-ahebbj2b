class Solution {
public:
    bool calc(vector<int>& nums, vector<int>& dp, int i) {
        if(i >= nums.size()) {
            return false;
        }
        if ( i == nums.size() - 1) {
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        for(int j=1; j <= min((int)nums.size() - i - 1, nums[i]); j++) {
            if(calc(nums, dp, i+j)){
                return dp[i] = true;
            }
        } 

        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return calc(nums, dp, 0);
    }
};
