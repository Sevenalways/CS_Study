## day50 今日任务5.25

1. 309.最佳买卖股票时机含冷冻期
2. 714.买卖股票的最佳时机含手续费



#### 309.最佳买卖股票时机含冷冻期

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0],  (i >= 2 ? dp[i -2][1] : 0) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        } 
        return dp[n - 1][1];
    }
};
```

优化为常数空间

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = -prices[0]; // 持有股票
        int dp1 = 0; // 不持有股票
        int pre0 = 0, pre1 = 0, ppre1 = 0;

        for (int i = 1; i < n; ++i) {
            pre0 = dp0;
            pre1 = dp1;
            dp0 = max(dp0, (i >= 2 ? ppre1 : 0) - prices[i]);
            dp1 = max(dp1, pre0 + prices[i]);
            ppre1 = pre1;
        }

        return dp1; 
    }
};

```

####  714.买卖股票的最佳时机含手续费

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp0 = -prices[0], dp1 = 0;
        for (int i = 1; i < n; i++) {
            int pre = dp0;
            dp0 = max(dp0, dp1 - prices[i]);
            dp1 = max(dp1, pre + prices[i] - fee);
        }
        return dp1;
    }
};
```

