class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 1, temp;

        for(int i=1; i<n; i++){
            temp = curr;
            curr = curr + prev;
            prev = temp; 
        }

        return curr;
    }
};
