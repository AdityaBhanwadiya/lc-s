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

        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);

        //base
        // dp[n][0] = dp[n][1] = 0;
        int profit = 0;

        for(int i=n-1;i>=0;i--) {
            for(int k = 0;k<=1;k++){
                if(k){
                    profit = max(-prices[i] + front1[0], 0 + front1[1]);
                } else{
                    profit = max(prices[i] + front2[1], 0 + front1[0]);
                }
                curr[k] = profit;
            }
            front2 = front1;
            front1 = curr;
            
        }
        return curr[1];
    }
};