## day55 今日任务5.30

1. 583.两个字符串的删除操作
2. 72.编辑距离

#### 583. 两个字符串的删除操作

[力扣题目链接](https://leetcode.cn/problems/delete-operation-for-two-strings/)

```cpp
class Solution {
public:
    // dfs(i, j) = dfs(i - 1, j - 1) else min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < m; i++) {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] : min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }
        }
        return dp[m][n];
    }
};
```

```cpp
class Solution {
public:
    // dfs(i, j) = dfs(i - 1, j - 1) else min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
    // 优化为一维数组
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 0; i < m; i++) {
            int pre = dp[0];
            dp[0]++;
            for (int j = 0; j < n; j++) {
                int tmp =  dp[j + 1];
                dp[j + 1] = s[i] == t[j] ? pre : min(dp[j], dp[j + 1]) + 1;
                pre = tmp;
            }
        }
        return dp[n];
    }
};
```





#### 72. 编辑距离

[力扣题目链接](https://leetcode.cn/problems/edit-distance/)

```cpp
class Solution {
public:
    // dfs[i][j] = dfs[i - 1][j - 1] if s[i] == t[j]
    // else dfs[i][j] = min(dfs(i, j - 1), dfs(i - 1, j), dfs(i - 1, j - 1)) + 1
    // 依次表示                 插入，          删除，             替换 
    // 插入：在此处插入t[j], 即j变小了，i不变
    // 删除：在此处删掉是s[i]，即i变小了，j不变
    // 替换：将s[i]变为t[j]，即i，j均变小
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化边界
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < m; i++) {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = s[i]== t[j] ? dp[i][j] :  
                min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
            }
        }
        return dp[m][n];

    }
};
```



```cpp
class Solution {
public:
    // dfs[i][j] = dfs[i - 1][j - 1] if s[i] == t[j]
    // else dfs[i][j] = min(dfs(i, j - 1), dfs(i - 1, j), dfs(i - 1, j - 1)) + 1
    // 依次表示                 插入，          删除，             替换 
    // 插入：在此处插入t[j], 即j变小了，i不变
    // 删除：在此处删掉是s[i]，即i变小了，j不变
    // 替换：将s[i]变为t[j]，即i，j均变小
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);// 第0行
        for (char x : s) {
            int pre = dp[0]++;
            for (int j = 0; j < n; j++) {
                int tmp = dp[j + 1];
                dp[j + 1] = x == t[j] ? pre : min(min(dp[j], dp[j + 1]), pre) + 1;
                pre = tmp;
            }
        }
        return dp[n];

    }
};
```

