## day49 今日任务5.24

1. 123.买卖股票的最佳时机III
2. 188.买卖股票的最佳时机IV



####  123.买卖股票的最佳时机III

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4));
        dp[0] = {-prices[0], 0, -prices[0], 0};
        for (int i = 1; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], -prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] + prices[i]);
            dp[i + 1][2] = max(dp[i][2], dp[i][1] - prices[i]);
            dp[i + 1][3] = max(dp[i][3], dp[i][2] + prices[i]);
        }
        return dp[n][3];
    }
};
```

```cpp
class Solution {
public:
    // 优化为1维
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(4);
        dp = {-prices[0], 0, -prices[0], 0};
        for (int i = 1; i < n; i++) {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        return dp[3];
    }
};

```

#### 188.买卖股票的最佳时机IV

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2 * k + 1, 0);
        for (int i = 0; i < k; i++) {
            dp[2 * i + 1] = -prices[0]; 
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[2 * j + 1] = max(dp[2 * j + 1], dp[2 * j] - prices[i]);
                dp[2 * j + 2] = max(dp[2 * j + 2], dp[2 * j + 1] + prices[i]);
            }
        }
        return dp.back();
    }
};
```

