class Solution {
private:
    int func (int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        //base
        if(i == prices.size()){
             return 0;
        }

        if(dp[i][buy] != -1)    return dp[i][buy];
        int profit = 0;
        // 1 -> you can buy
        // 0 -> you can sell

        if(buy){
            profit = max(-prices[i] + func(i+1, 0, prices, dp), 0 + func(i + 1, 1, prices, dp));
        } else{
            profit = max(prices[i] + func(i+1, 1, prices, dp), 0 + func(i + 1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        vector<int> ahead(3, 0), curr(3, 0);

        //base
        ahead[0] = ahead[1] = 0;
        int profit = 0;

        for(int i=n-1;i>=0;i--) {
            for(int k = 0;k<=1;k++){
                if(k){
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                } else{
                    profit = max(prices[i] + ahead[1], 0 + ahead[0]);
                }
                curr[k] = profit;
            }
            ahead = curr;
            
        }
        return ahead[1];
    }
};