class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int prev1 = 0, prev2 = 0;
        int curr1 = nums[0], curr2 = nums[1];
        int temp;
        for(int i=1; i<nums.size()-1; i++){
            temp = prev1;
            prev1 = curr1;
            curr1 = max(curr1, temp + nums[i]);
            temp = prev2;
            prev2 = curr2;
            curr2 = max(curr2, temp + nums[i+1]);
        }

        return max(curr1, curr2);
    }
};
