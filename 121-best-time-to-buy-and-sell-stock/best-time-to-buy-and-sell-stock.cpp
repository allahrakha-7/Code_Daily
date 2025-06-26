class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // base condition
        if (prices.size() < 2) {
            return 0;
        }

        int buyTime = 0;
        int sellTime = 1;

        int maxProfit = 0;

        while (buyTime < sellTime && sellTime < prices.size()) {

            if (prices[sellTime] > prices[buyTime]) {

                int currentProfit = prices[sellTime] - prices[buyTime];

                maxProfit = max(maxProfit, currentProfit);

            } else {
                buyTime = sellTime;
            }
            sellTime++;
        }
        return maxProfit;
    }
};