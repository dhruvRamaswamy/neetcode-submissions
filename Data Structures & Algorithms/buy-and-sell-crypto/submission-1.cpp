class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            
            maxProfit = max(prices[i] - lowestPrice, maxProfit);

            lowestPrice = min(lowestPrice, prices[i]);
        }
        return maxProfit;
    }
};
