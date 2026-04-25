class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int currEnd = 0, nextEnd = 0, jumps = 0;
        for(int i=0; i<n; i++){
            nextEnd = max(nextEnd, i + nums[i]);
            if(i == currEnd){
                jumps++;
                currEnd = nextEnd;
                if(currEnd >= n-1) return jumps;
            }
        }

        return jumps;
    }
};
