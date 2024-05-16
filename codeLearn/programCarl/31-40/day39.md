## day39 今日任务5.14

1. 62.不同路径

2. 63.不同路径II

   



####  62.不同路径

[力扣题目链接](https://leetcode.cn/problems/unique-paths/)

方法1：动态规划

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};
```

方法2：数论

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
```



####  63. 不同路径 II

[力扣题目链接](https://leetcode.cn/problems/unique-paths-ii/)

只需要判断一下

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = (obstacleGrid[0][0] == 0); // 初值
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (j > 0 && obstacleGrid[i][j - 1] == 0)// j > 0 && obstacleGrid[i][j] == 0 也可
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
```

