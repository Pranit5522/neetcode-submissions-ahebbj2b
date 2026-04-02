class Solution {
public:
    void getPalindromeCount(string s, int left, int right, int &count){
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for(int i=0; i<n; i++){
            getPalindromeCount(s, i, i, count); //Odd Case
            getPalindromeCount(s, i, i+1, count); //Even Case
        }

        return count;
    }
};

