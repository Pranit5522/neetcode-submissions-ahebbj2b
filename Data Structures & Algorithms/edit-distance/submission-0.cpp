class Solution {
public:
    int calc(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if(i==word1.size() || j==word2.size()){
            return max(word1.size() - i, word2.size() - j);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = calc(word1, word2, i+1, j+1, dp);
        }

        return dp[i][j] = 1 + min(
            min(
                calc(word1, word2, i+1, j+1, dp),
                calc(word1, word2, i+1, j, dp)
            ),
            calc(word1, word2, i, j+1, dp)
        );
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return calc(word1, word2, 0, 0, dp);
    }
};
