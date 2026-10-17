class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Super basic sliding window problem:
        // So this isn't a sliding window problem

        if(prices.empty()){
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice) {
                // No profit to be made...
                minPrice = prices[i];
            }
            else {
                // So there is a profit to be made/
                int profit = prices[i] - minPrice;
                // printf("profit: %d", profit);
                if(profit > maxProfit) {
                    maxProfit = profit;
                }
                
            }
            printf("Max Profit %d, Min price: %d\n", maxProfit, minPrice);
        }
        return maxProfit;
    }
};
