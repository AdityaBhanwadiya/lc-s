class Solution {
private:
    int func (int i, int amount, vector<int>& coins, vector<int>& prev, vector<int>& curr) {
        // base
        // if(i == 0){
        //     if(amount % coins[0] == 0)  return amount/coins[0];
        //     return 1e9;
        // }

        for(int i = 1;i<=amount;i++){
            if(i%coins[0] == 0)    
                prev[i] = i/coins[0];
            else
                prev[i] = 1e9;
        }

        // if(dp[i][amount] != -1) 
        //     return dp[i][amount];

        //take

        for(int i=1;i<coins.size();i++){
            for(int k = 1;k<=amount;k++) {
                int take = INT_MAX;
                if(k >= coins[i])
                    take = 1 + curr[k - coins[i]];
                int notTake = 0 + prev[k];

                curr[k] = min(take, notTake);
            }
            prev = curr;
        }
        

        return prev[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int>prev(amount+1, 0), curr(amount + 1, 0);

        int ans = func (n-1, amount, coins, prev, curr);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};