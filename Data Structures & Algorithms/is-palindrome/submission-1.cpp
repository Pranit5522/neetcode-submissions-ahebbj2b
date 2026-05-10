class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        
        while(i<j) {
            if((!isalpha(s[i]) && !isdigit(s[i])) || (!isalpha(s[j]) && !isdigit(s[j]))) {
                if(!isalpha(s[i]) && !isdigit(s[i])) i++;
                if(!isalpha(s[j]) && !isdigit(s[j])) j--;
            }
            else {
                if(tolower(s[i]) == tolower(s[j])) {
                    i++; j--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
