class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};