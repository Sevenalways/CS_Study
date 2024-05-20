## day41 今日任务5.16

1. 01背包问题 二维

2. 01背包问题 一维 滚动数组

3. 416.分割等和子集

   

####  01背包 

**0-1背包**：有n件物品和一个最多能背重量为capacity 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。

回溯三问：

1. 当前操作？枚举第`i`个物品选或不选
2. 子问题？在剩余容量为`c`时，从`前`i个物品中得到的最大价值和
3. 下一个子问题？分类讨论：
   - 不选：剩余容量为`c`，从`前i-1`个
   - 选：剩余容量为`c- weight[i]`，从`前i-1`个

`dfs(i,c) = max(dfs(i - 1, c), dfs(i - 1, c - weight[i]) + value[i])`



#### 416.分割等和子集

[力扣题目链接](https://leetcode.cn/problems/partition-equal-subset-sum/)

`dfs(i, c) = dfs(i - 1, c) || dfs(i - 1, c - nums[i])`

或者`dfs(i, c) = dfs(i - 1, c) + dfs(i - 1, c - nums[i]) > 0`

```cpp
class Solution {
public:
    // 方法1 记忆化搜索
    // dfs(i, c) = dfs(i - 1, c) || dfs(i - 1, c - nums[i])
    bool canPartition(vector<int>& nums) {
        int target = reduce(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;
        int n = nums.size(), memo[n][target + 1];
        memset(memo, -1, sizeof(memo));
        function<bool(int, int)> dfs = [&](int i, int c) -> bool {
            if (c == 0) return true;// 任意过程中只要找到c == 0了，就可以直接返回ture
            if (i < 0 || c < 0) return false;
            int &res = memo[i][c];
            if (res != -1) return res == 1;
            return res = dfs(i - 1, c) || dfs(i - 1, c - nums[i]) ? 1 : 0; 
        };
        return dfs(n - 1, target);
    }
};
```

```cpp
class Solution {
public:
    // 方法2 翻译成递推
    // dfs(i, c) = dfs(i - 1, c) || dfs(i - 1, c - nums[i])
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;
        int n = nums.size();
        bool f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= target; c++) {
                if (c < nums[i]) f[i + 1][c] = f[i][c];
                else f[i + 1][c] = f[i][c] || f[i][c - nums[i]];
            }
        }
        return f[n][target];
    }
};
```

```cpp
class Solution {
public:
    // 方法3 空间优化
    // dfs(i, c) = dfs(i - 1, c) || dfs(i - 1, c - nums[i])
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;
        int n = nums.size();
        bool f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 0; i < n; i++) {
            for (int c = target; c >= nums[i]; c--) {
                f[c] = f[c] || f[c - nums[i]];
            }
        }
        return f[target];
    }
};
```



