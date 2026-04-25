class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1, right = 1, maxProd = INT_MIN, n = nums.size();

        for(int i=0; i<n; i++) {
            left *= nums[i];
            right *= nums[n-i-1];

            maxProd = max(maxProd, max(left, right));
            if(!left) left = 1;
            if(!right) right = 1;
        }

        return maxProd;
    }
};
