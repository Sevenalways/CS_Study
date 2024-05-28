## day54 今日任务5.29

1. 392.判断子序列
2. 115.不同的子序列



####  392.判断子序列

[力扣题目链接](https://leetcode.cn/problems/is-subsequence/)

双指针

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        for (int i = 0, j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                // 若已经遍历完 s ，则提前返回 true
                if (++i == s.size())
                    return true;
            }
        }
        return false;
    }
};
```



动态规划

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                if (s[i] == t[j])  {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else  dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
        return dp[m][n] == m;
    }
};
```

动态规划+剪枝

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return false;
        vector<bool> dp(n + 1, true);
        for (int i = 0; i < m; i++) {
            int pre = dp[i];
            for (int j = i; j < n; j++) {
                int tmp = dp[j + 1];
                if (s[i] != t[j] || pre == false) {
                    dp[j + 1] = false;
                    pre = tmp;
                }
                else break;
            }
        }
        return dp[n];
    }
};
```





#### 115.不同的子序列

[力扣题目链接](https://leetcode.cn/problems/distinct-subsequences/)

```cpp
class Solution {
public:
    // dp[i + 1][j + 1] = s[i]== t[j] ? dp[i][j] + dp[i][j + 1] : dp[i][j + 1]
    int numDistinct(string s, string t) {
        const int MOD = 1E9 + 7;
        int m = s.size(), n = t.size();
        if (m < n) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = (dp[i][j + 1] + (t[j] == s[i] ? dp[i][j] : 0)) % MOD;
            }
        }
        return dp[m][n];
    }
};
```



```cpp
class Solution {
public:
    // 优化为一维
    // dp[i + 1][j + 1] = s[i]== t[j] ? dp[i][j] + dp[i][j + 1] : dp[i][j + 1]
    int numDistinct(string s, string t) {
        const int MOD = 1E9 + 7;
        int m = s.size(), n = t.size();
        if (m < n) return false;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            dp[0] = 1;
            for (int j = n - 1; j >= 0; j--) {
                dp[j + 1] = (dp[j + 1] + (t[j] == s[i] ? dp[j] : 0)) % MOD;
            }
        }
        return dp[n];
    }
};
```

