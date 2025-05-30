class Solution {
private:
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

    int helper(int n, vector<int>& nums) {

        // vector<int> dp(n+1, 0);

        // dp[0] = nums[0];
        // int neg = 0;

        int prev1 = nums[0], prev2 = 0;

        for(int i=1;i<n;i++) {
            int pick = nums[i]; if(i > 1) pick += prev2;
            int notPick = 0 + prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];


        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }

        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }

        return max(helper(n-1, temp1), helper(n-1, temp2));
    }
};