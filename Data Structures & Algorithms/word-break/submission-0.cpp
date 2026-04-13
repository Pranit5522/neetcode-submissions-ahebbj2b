class Solution {
public:
    bool checkIsBreakable(string s, vector<string>& wordDict, int i, int j, vector<vector<int>>& dp) {
        if(i == s.length()) return j == i;
        if(dp[i][j] != -1) return dp[i][j];

        bool cond = false;
        if(find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end()){
            cond = checkIsBreakable(s, wordDict, i+1, i+1, dp);
        } 

        return dp[i][j] = cond || checkIsBreakable(s, wordDict, i+1, j, dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return checkIsBreakable(s, wordDict, 0, 0, dp);
    }
};
