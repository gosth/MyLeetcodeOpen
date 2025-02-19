class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) {
                return 0;
            }
            std::vector <std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));
            dp[0][0] = -1 * prices.front();
            for (int i = 1; i < prices.size(); ++i) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
                dp[i][1] = dp[i - 1][0] + prices[i];
                dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
            }
            int endIndex = prices.size() - 1;
            return std::max(dp[endIndex][1], dp[endIndex][2]);
        }
    };