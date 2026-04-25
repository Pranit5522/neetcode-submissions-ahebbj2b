class Solution {
public:
    bool calc(string& s, vector<string>& wordDict, int i, vector<int>& dp){
        if(i == s.size()){
            return true;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        for(string word: wordDict){
            if(s.substr(i, word.size()) == word){
                if(calc(s, wordDict, i + word.size(), dp)) {
                    return dp[i] = true;
                }
            }
        }
        
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return calc(s, wordDict, 0, dp);
    }
};
