class Solution {
private:
    int func (int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // base
        // if(i == 0){
        //     if(amount % coins[0] == 0)  return amount/coins[0];
        //     return 1e9;
        // }

        for(int i = 1;i<=amount;i++){
            if(i%coins[0] == 0)    
                dp[0][i] = i/coins[0];
            else
                dp[0][i] = 1e9;
        }

        // if(dp[i][amount] != -1) 
        //     return dp[i][amount];

        //take

        for(int i=1;i<coins.size();i++){
            for(int k = 1;k<=amount;k++) {
                int take = INT_MAX;
                if(k >= coins[i])
                    take = 1 + dp[i][k - coins[i]];
                int notTake = 0 + dp[i-1][k];

                dp[i][k] = min(take, notTake);
            }
        }
        

        return dp[i][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        int ans = func (n-1, amount, coins, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};