class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxRight(n, 0);


        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }

        int count = 0, maxLeft = 0;
        for(int i=1; i<n; i++){
            maxLeft = max(maxLeft, height[i-1]);
            count += max(0, min(max(maxLeft, height[i]), maxRight[i]) - height[i]);
        }

        return count;
    }
};
