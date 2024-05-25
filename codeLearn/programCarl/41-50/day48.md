## day48 今日任务5.23

1. 121.买卖股票的最佳时机
2. 122.买卖股票的最佳时机II



####  121. 买卖股票的最佳时机

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

```cpp
// 贪心 1
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int min_price = prices[0];
        for (int p : prices) {
            ans = max(ans, p - min_price);
            min_price = min(min_price, p);
        }
        return ans;
    }
};
```

`dp[i][0] `表示第i天持有股票所得最多现金 ，`dp[i][1]` 表示第i天不持有股票所得最多现金

转移方程` dp[i + 1][0] = max(dp[i][0], -prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] + prices[i]);`


```cpp
// 动态规划
class Solution {
public:
    //dp[i][0] 表示第i天持有股票所得最多现金 ，dp[i][1] 表示第i天不持有股票所得最多现金
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], -prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] + prices[i]);
        }
        return dp[n][1];
    }
};
```

```cpp
class Solution {
public:
    //dp[i][0] 表示第i天持有股票所得最多现金 ，dp[i][1] 表示第i天不持有股票所得最多现金
    // 空间优化一下
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2, 0);
        dp[0] -= prices[0];
        dp[1] = 0;
        for (int i = 0; i < n; i++) {
            int pre = dp[0];
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], pre + prices[i]);
        }
        return dp[1];
    }
};
```



####  122.买卖股票的最佳时机II

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

```cpp
// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];// 可以同一天先买入再卖出
            }
        }
        return ans;
    }
};
```

`dp[i][0] `表示第i天持有股票所得最多现金 ，`dp[i][1]` 表示第i天不持有股票所得最多现金

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] - prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] + prices[i]);
        }
        return dp[n][1];
    }
};
```

```cpp
class Solution {
public:
    // 动态规划 优化为一维
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2);
        dp[0] -= prices[0];
        dp[1] = 0;
        for (int i = 1; i < n; i++) {
            int pre = dp[0];
            dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[1], pre + prices[i]);
        }
        return dp[1];
    }
};
```

