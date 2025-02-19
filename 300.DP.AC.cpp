class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            int temp = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    temp = dp[j] > temp ? dp[j] : temp;
                }
            }
            dp[i] = temp + 1;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};