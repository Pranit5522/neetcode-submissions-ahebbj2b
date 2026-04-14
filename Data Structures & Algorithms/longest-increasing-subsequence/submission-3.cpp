class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>());

        for(int i=0; i<n; i++) {
            dp[i].push_back(1);
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i].push_back(max(dp[j][j] + 1, dp[i][j]));
                }
                else{
                    dp[i].push_back(dp[i][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, dp[i][i]);
        return ans;
    }
};