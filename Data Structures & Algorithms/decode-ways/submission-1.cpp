class Solution {
public:
    int calPossibilities(string s, vector<int> &dp, int i) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        dp[i] = calPossibilities(s, dp, i+1);
        if(
            s[i] == '1' ||
            (s[i] == '2' && i < s.size() - 1 && s[i+1] <= '6' && s[i+1] >= '0') 
        ){
            dp[i] += calPossibilities(s, dp, i+2);
        }

        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return calPossibilities(s, dp, 0);
    }
};
