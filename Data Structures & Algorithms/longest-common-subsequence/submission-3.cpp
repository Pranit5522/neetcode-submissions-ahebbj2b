class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = max(1 + dp[i-1][j-1], dp[i][j]);
                }
            }
        }

        return dp[n][m];
    }
};
//   _ A B C B C B A
// _ 0 0 0 0 0 0 0 0
// A 0 1 1 1 1 1 1 1
// B 0 1 2 2 2 2 2 2
// C 0 1 2 3 3 3 3 3
// B 0 1 2 2 4 4 4 4
// A 0 1 2 2 4 4 4 5









