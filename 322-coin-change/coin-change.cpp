class Solution {
private:
    int func (int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // base
        if(i == 0){
            if(amount % coins[0] == 0)  return amount/coins[0];
            return 1e9;
        }

        if(dp[i][amount] != -1) 
            return dp[i][amount];

        //take
        int take = INT_MAX;
        if(amount >= coins[i])
            take = 1 + func (i, amount - coins[i], coins, dp);
        //not take
        int notTake = 0 + func(i-1, amount, coins, dp);

        return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = func (n-1, amount, coins, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};