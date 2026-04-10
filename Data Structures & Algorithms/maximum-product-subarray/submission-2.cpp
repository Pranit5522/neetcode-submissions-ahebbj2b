class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prodLeft = 1, prodRight = 1, maxProd = INT_MIN, n = nums.size();

        for(int i=0; i<n; i++){
            prodLeft *= nums[i];
            prodRight *= nums[n-1-i];

            maxProd = max(maxProd, max(prodLeft, prodRight));

            if(!prodLeft) prodLeft = 1;
            if(!prodRight) prodRight = 1;
        }

        return maxProd;
    }
};
