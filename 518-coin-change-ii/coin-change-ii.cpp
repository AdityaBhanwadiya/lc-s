class Solution {
private:
    int func (int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // base
        if(i == 0){
            return (amount % coins[0] == 0) ? 1 : 0;
        }

        if(dp[i][amount] != -1) 
            return dp[i][amount];

        //take
        int take = 0;
        if(amount >= coins[i])
            take = func (i, amount - coins[i], coins, dp);
        //not take
        int notTake = func(i-1, amount, coins, dp);

        return dp[i][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = func (n-1, amount, coins, dp);
        return ans;
    }
};