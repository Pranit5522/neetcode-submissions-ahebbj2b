class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size(), prev = 1, curr = 1, temp;

        for(int i=1; i<n; i++){
            temp = 0;
            if(s[i] != '0'){
                temp += curr;
            }
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                temp += prev;
            }

            prev = curr;
            curr = temp;
        }

        return curr;
    }
};
