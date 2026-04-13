class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;

        for(int i=1; i<=n; i++){
            for(string word: wordDict){
                int j = i - word.size();
                if(dp[j] && j >= 0 && s.substr(j, word.size()) == word){
                    dp[i] = true;
                }
            }
        }

        return dp[n];
    }
};
