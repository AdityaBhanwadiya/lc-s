class Solution {
public:
    // next [24, 12, 4, 1]
    // prev [1, 1, 2, 6]
    // ans [24, 12, 8, 6]
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> next (n);
        vector<int> prev (n);

        int nextPro = 1;
        for(int i=n-1;i>=0;i--){
            next[i] = nextPro; 
            nextPro *= nums[i];
        }

        int prevPro =  1;
        for(int i=0;i<n;i++) {
            prev[i] = prevPro; // 1 1 2 6 
            prevPro *= nums[i];
        }

        vector<int> result;
        for(int i=0;i<n;i++) {
            result.push_back(next[i] * prev[i]);
        }

        return result;
    }
};
