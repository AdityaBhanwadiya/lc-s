class Solution {
private:
    int func (int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        //base
        if(i == prices.size()){
             return 0;
        }
        if(cap == 0)    return 0;

        if(dp[i][buy][cap] != -1)    return dp[i][buy][cap];

        int profit = 0;
        // 1 -> you can buy
        // 0 -> you can sell

        if(buy){
            profit = max(-prices[i] + func(i+1, 0, cap, prices, dp), 0 + func(i + 1, 1, cap, prices, dp));
        } else{
            profit = max(prices[i] + func(i+1, 1, cap-1, prices, dp), 0 + func(i + 1, 0, cap, prices, dp));
        }
        return dp[i][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(4, 0)));

        for(int i=0;i<=1;i++) {
            for(int j = 0;j<=2;j++){
                dp[n][i][j] = 0;
            }
        }

        for(int i=0;i<=n;i++) {
            for(int j = 0;j<=1;j++){
                dp[i][j][0] = 0;
            }
        }
        int profit = 0;
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j){
                        profit = max(-prices[i] + dp[i+1][0][k], 0 + dp[i + 1][1][k]);
                    } else{
                        profit = max(prices[i] + dp[i+1][1][k-1], 0 + dp[i + 1][0][k]);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }


        return dp[0][1][2];

    }
};