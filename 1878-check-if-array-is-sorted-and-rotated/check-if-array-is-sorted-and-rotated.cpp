class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breakPoints = 0;

        for(int i=1;i<n;i++) {
            if(nums[i] < nums[i-1])
                breakPoints++;
        }

        if(nums[n-1] > nums[0])
            breakPoints++;

        if(breakPoints > 1)     return false;
        return true;
    }
};