class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPriceToBuy = prices[0];
        int maxProfit = 0;

        for(int i=1;i<n;i++){
            int currentPrice = prices[i];
            if(currentPrice < minPriceToBuy){
                minPriceToBuy = currentPrice;
            }
            if(maxProfit < currentPrice - minPriceToBuy){
                maxProfit = currentPrice - minPriceToBuy;
            }
        }
        return maxProfit;

    
    }
};