class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, maxPos = 0, j;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++) dp[i][i] = true;
        for(int i=1; i<n; i++) dp[i][i-1] = true;

        for(int strLen = 2; strLen <= n; strLen++){
            for(int i = 0; i+strLen <= n; i++){
                j = i + strLen - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    maxLen = strLen;
                    maxPos = i;
                }
            }
        }

        return s.substr(maxPos, maxLen);
    }
};
