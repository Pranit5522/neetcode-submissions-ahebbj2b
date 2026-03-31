class Solution {
public:
    int climbStairs(int n) {
        int curr = 1;
        int prev = 1;
        int temp;

        for(int i=1; i<n; i++){
            temp = prev;
            prev = curr;
            curr += temp;
        }

        return curr;
    }
};
