class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = nums[0];
        int temp;

        for(int i=1; i< nums.size(); i++){
            temp = prev;
            prev = curr;
            curr = max(curr, temp + nums[i]);
        }

        return curr;
    }
};
