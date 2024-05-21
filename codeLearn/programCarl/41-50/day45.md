## day45 今日任务5.20

1. 70.爬楼梯(进阶)
2. 322.零钱兑换
3. 279.完全平方数

#### 70. 爬楼梯（进阶版）

[卡码网：57. 爬楼梯](https://kamacoder.com/problempage.php?pid=1067)

如果m = 2 就是力扣70爬楼梯

求排列问题，先背包再物品

装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 1; j <= m; j++) { // 遍历物品
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        cout << dp[n] << endl;
    }
}
```

#### 322. 零钱兑换

[力扣题目链接](https://leetcode.cn/problems/coin-change/)

求最小值，无论是排列还是组合都可以，因此顺序不重要

```cpp
class Solution {
public:
    // 完全背包 恰好装满 求最小值
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = coins[i]; c <= amount; c++) {
                dp[c] = min(dp[c], dp[c - coins[i]] + 1);
            }
        }
        return dp[amount] < amount + 1 ? dp[amount] : -1; 
    }
};
```

#### 279.完全平方数

[力扣题目链接](https://leetcode.cn/problems/perfect-squares/)

```cpp
class Solution {
public:
    // 完全背包 恰好 求最小值
    int numSquares(int n) {
        int mx = (int) pow(n, 0.5) + 1;
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= mx; i++) {// 遍历物品
            int num = i * i;
            for (int c = num; c <= n; c++) {
                dp[c] = min(dp[c - num] + 1, dp[c]);
            }
        } 
        return dp[n];
    }
};
```

