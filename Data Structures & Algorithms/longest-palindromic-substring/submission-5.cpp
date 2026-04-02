class Solution {
public:
    void updateDP(string s, vector<bool>& dp, int i, int j, int strLen, int& maxLen, int& maxPos){
        if(s[i] == s[j] && dp[i+1]){
            dp[i] = true;
            maxLen = strLen;
            maxPos = i;
        } else {
            dp[i] = false;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, maxPos = 0, j;
        vector<bool> odd(n, true);
        vector<bool> even(n, true);

        for(int strLen = 2; strLen <= n; strLen++){
            for(int i = 0; i+strLen <= n; i++){
                j = i + strLen - 1;
                strLen % 2 ? updateDP(s, odd, i, j, strLen, maxLen, maxPos) : updateDP(s, even, i, j, strLen, maxLen, maxPos);
            }
        }

        return s.substr(maxPos, maxLen);
    }
};
