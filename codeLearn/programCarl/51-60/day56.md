## day56 今日任务5.31

1. 647.回文子串
2. 516.最长回文子序列

#### 647. 回文子串

[力扣题目链接](https://leetcode.cn/problems/palindromic-substrings/)

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
        return result;
    }
};
```

```cpp
// 空间优化为一维
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<bool> dp(n, false);
        int result = 0; 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (s[i] == s[j] && (j - i <= 1 || dp[j - 1])) {
                    dp[j] = true;
                    result++;
                } else {
                    dp[j] = false;
                }
            }
        }
        return result;
    }
};
```

```cpp
// 双指针
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
```



####  516.最长回文子序列

[力扣题目链接](https://leetcode.cn/problems/longest-palindromic-subsequence/

```cpp
class Solution {
public:
    // 动态规划 dp[i][j] 表示以[i, j]范围内的最长回文子序列
   // 转移方程 dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
    // 初值 ：dp[i][i] = 1; 单个字符本身是回文，长度为1
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
```



```cpp
class Solution {
public:
    // 空间优化为一维
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;// 单个字符本身是回文，长度为1
            int pre = 0;//dp[j - 1]
            for (int j = i + 1; j < n; j++) {//从i + 1开始遍历
                int tmp = dp[j];
                dp[j] = s[i] == s[j] ? pre + 2 : max(dp[j], dp[j - 1]);
                pre = tmp;
            }
        }
        return dp[n - 1];
    }
};
```

