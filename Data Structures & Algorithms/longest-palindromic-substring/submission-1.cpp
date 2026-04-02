class Solution {
public:
    pair<int, int> getPalindromeLength(string s, int left, int right, int count){
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count += 2;
            left--;
            right++;
        }

        return make_pair(left+1, count);
    }
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, maxPos = 0;
        pair<int, int> res;

        for(int i=0; i<n; i++){
            //Odd Case
            res = getPalindromeLength(s, i-1, i+1, 1);
            if(res.second > maxLen){
                maxLen = res.second;
                maxPos = res.first;
            }

            res = getPalindromeLength(s, i, i+1, 0);
            if(res.second > maxLen){
                maxLen = res.second;
                maxPos = res.first;
            }
        }

        return s.substr(maxPos, maxLen);
    }
};
