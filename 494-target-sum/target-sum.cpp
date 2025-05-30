class Solution {
private:
    int solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
         
            if (i == 0) {
                if (sum == 0) {
                    return 1;
                }
                return 0;
            }
        
            if (dp[i][sum] != -1) {
                return dp[i][sum];
            }
            
            dp[i][sum] = solve(i - 1, sum, arr, dp);
        

            if (sum >= arr[i - 1]) {
                dp[i][sum] = (dp[i][sum] + solve(i - 1, sum - arr[i - 1], arr, dp));
            }
        
            return dp[i][sum];
         
     }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
            int totalSum = 0;
        
            for (int i = 0; i < n; ++i) {
                totalSum += arr[i];
            }
    
            if (totalSum < d || (totalSum - d) % 2) {
                return 0;
            }
        
            int target = (totalSum - d) / 2;
            
            vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        
            return solve(n, target, arr, dp);
    
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};