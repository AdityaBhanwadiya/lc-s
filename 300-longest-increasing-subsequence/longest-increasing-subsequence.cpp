class Solution {
private:
    int func (int i, int prev, vector<int>& nums, vector<vector<int>> dp) {
        //base
        if(i == nums.size())    return 0;

        if(dp[i][prev + 1] != -1)   return dp[i][prev + 1];
        // explore
        int notTake = 0 + func(i+1, prev, nums, dp);

        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + func (i+1, i, nums, dp);
        }

        // return 
        return dp[i][prev + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // base
        // for(int prev = 0;prev<=n;prev++){
        //     dp[n][prev] = 0;
        // }

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--) {
                // explore
                int notTake = 0 + dp[i+1][j + 1];

                int take = INT_MIN;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }

                // return 
                dp[i][j + 1] = max(notTake, take);
            }
        }
        return dp[0][-1+1];
    }
};