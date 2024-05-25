<<<<<<< HEAD
## day43 今日任务5.18

1. 完全背包

2. 518.零钱兑换II

3. 377.组合总和IV

#### 518.零钱兑换II

[力扣题目链接](https://leetcode.cn/problems/coin-change-ii/)

装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

```cpp
class Solution {
public:
    // 完全背包问题，求方案数
    // dfs(i, c) = dfs(i - 1, c) + dfs(i, c - coins[i])
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {//遍历物品
            for (int c = coins[i]; c <= amount; c++) {// 遍历背包
                f[c] += f[c - coins[i]];
            }
        }
        return f[amount];
    }
};

```

**如果求组合数就是外层for循环遍历物品，内层for遍历背包**->518

**如果求排列数就是外层for遍历背包，内层for循环遍历物品**->377

#### 377. 组合总和 Ⅳ

[力扣题目链接](https://leetcode.cn/problems/combination-sum-iv/)

装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

```cpp
class Solution {
public:
    // 完全背包问题
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {// 遍历背包
            for (int x : nums) {// 遍历物品
                if (x <= i) {
                    f[i] = (0ll + f[i] + f[i - x]) % INT_MAX;// 测试数据累计和超过了int，但答案保证为int
                }
            }
        }
        return f[target];
    }
};

```

=======
## day43 今日任务5.18

1. 完全背包

2. 518.零钱兑换II

3. 377.组合总和IV

#### 518.零钱兑换II

[力扣题目链接](https://leetcode.cn/problems/coin-change-ii/)

装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

```cpp
class Solution {
public:
    // 完全背包问题，求方案数 组合数
    // dfs(i, c) = dfs(i - 1, c) + dfs(i, c - coins[i])
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {//遍历物品
            for (int c = coins[i]; c <= amount; c++) {// 遍历背包
                f[c] += f[c - coins[i]];
            }
        }
        return f[amount];
    }
};

```

**如果求组合数就是外层for循环遍历物品，内层for遍历背包**->518

**如果求排列数就是外层for遍历背包，内层for循环遍历物品**->377

#### 377. 组合总和 Ⅳ

[力扣题目链接](https://leetcode.cn/problems/combination-sum-iv/)

装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

```cpp
class Solution {
public:
    // 完全背包问题 排列数
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {// 遍历背包
            for (int x : nums) {// 遍历物品
                if (x <= i) {
                    f[i] = (0ll + f[i] + f[i - x]) % INT_MAX;// 测试数据累计和超过了int，但答案保证为int
                }
            }
        }
        return f[target];
    }
};

```

>>>>>>> 81e8f5725848bcf81c64e20e65226345e729b16c
