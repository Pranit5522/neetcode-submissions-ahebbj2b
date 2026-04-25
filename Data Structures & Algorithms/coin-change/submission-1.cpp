class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                if(dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
//    0 1 2 3 4 5 6 7 8 9 10 11 12
// -  0 i i i i i i i i i i  i  i
// 1  0 1 2 3 4 5 6 7 8 9 10 11 12
// 5  0 1 2 3 4 1 2 3 4 5  2  3  4
// 10 0 1 2 3 4 1 2 3 4 5  1  2  3