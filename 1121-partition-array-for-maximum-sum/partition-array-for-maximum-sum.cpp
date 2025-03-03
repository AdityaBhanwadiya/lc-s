class Solution {
private:
    int func (int i, int n, vector<int>& arr, int k, vector<int>& dp) {
        //base
        if (i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int len = 0, maxi = INT_MIN, maxSum = 0, sum = 0;
        for(int j = i;j < min(n, i+k);j++) {
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len * maxi) + func (j+1, n, arr, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(arr.size()+1, 0);

        for(int i=n-1;i>=0;i--) {
            int len = 0, maxi = INT_MIN, maxSum = 0, sum = 0;
            for(int j = i;j < min(n, i+k);j++) {
                len++;
                maxi = max(maxi, arr[j]);
                sum = (len * maxi) + dp[j+1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};