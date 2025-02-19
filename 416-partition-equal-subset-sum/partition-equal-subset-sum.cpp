class Solution {
private:
    // bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    //     if (target == 0)
    //         return true;

    //     if (ind == 0)
    //         return arr[0] == target;

    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];

    //     bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    //     bool taken = false;
    //     if (arr[ind] <= target)
    //         taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    //     return dp[ind][target] = notTaken || taken;
    // }

    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

        for(int i=0;i<n;i++)    dp[i][0]=0;

        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        for(int ind=1;ind<n;ind++) {
            for(int target = 1;target<=k;target++){
                bool notTaken = dp[ind - 1][target];

                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = notTaken || taken;
            }
        }

        return dp[n - 1][k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(sum % 2 != 0)    return false;
        int target = sum/2;

        return isSubsetSum(nums, target);
    }
};