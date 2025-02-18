class Solution {
// private:
    // int func(int i, int n, vector<int>& nums, vector<int>& dp) {
        //base
        // if(i < 0)  {
        //     return 0;
        // }
        // if(i == 0)  return nums[0];

        // if(dp[i] != -1) return dp[i];

        // int pick = nums[i] + func(i-2, n, nums, dp);
        // int notPick = 0 + func(i-1, n, nums, dp);

        // return dp[i] = max(pick, notPick);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];

        vector<int> dp(n+1, 0);

        dp[0] = nums[0];

        for(int i=1;i<n;i++) {
            int pick = nums[i]; if(i > 1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];

            dp[i] = max(pick, notPick);

        }
        return dp[n-1];
    }
};