## day53 今日任务5.28

1. 1143.最长公共子序列
1. 1035.不相交的线
1. 53.最大子序列和





#### 1143.最长公共子序列

[力扣题目链接](https://leetcode.cn/problems/longest-common-subsequence/)

```cpp
class Solution {
public:
    // 二维
    // f[i + 1][j + 1] = f[i][j] + 1 if s[i] == t[j] else max(f[i][j + 1], f[i + 1][j])
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n][m];
    }
};
```

```cpp
class Solution {
public:
    // 二维表达式
    // f[i + 1][j + 1] = f[i][j] + 1 if s[i] == t[j] else max(f[i][j + 1], f[i + 1][j])
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; i++) {
            int pre = dp[0];// 初始为第一列或者写0，因为第一列永远为0
            for (int j = 0; j < m; j++) {
                int tmp = dp[j + 1];// 先保存好之前的左上角的值
                if (s[i] == t[j]) dp[j + 1] = pre + 1;
                else dp[j + 1] = max(dp[j], dp[j + 1]);
                pre = tmp;
            }
        }
        return dp[m];
    }
};
```

####  1035.不相交的线

[力扣题目链接](https://leetcode.cn/problems/uncrossed-lines/)

```cpp
class Solution {
public:
    // dp[i + 1][j + 1] 表示能连接的最大线，则
    // dp[i + 1][j + 1] = nums1[i] == nums2[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]) 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {    
                dp[i + 1][j + 1] = nums1[i] == nums2[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[m][n];
    }
};
```

```cpp
class Solution {
public:
    // dp[i + 1][j + 1] 表示能连接的最大线，则
    // dp[i + 1][j + 1] = nums1[i] == nums2[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]) 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int pre = dp[0];
            for (int j = 0; j < n; j++) { 
                int tmp = dp[j + 1];  
                dp[j + 1] = nums1[i] == nums2[j] ? pre + 1 : max(dp[j], dp[j + 1]);
                pre = tmp;
            }
        }
        return dp[n];
    }
};
```





#### 53. 最大子序和

[力扣题目链接](https://leetcode.cn/problems/maximum-subarray/)

dp[i] 表示以nums[i] 结尾的连续子数组最大和

转移方程 dp[i + 1] = dp[i] >= 0 ? dp[i] + nums[i] : nums[i];

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0, ans = INT_MIN;
        for (int x : nums) {
            s = max(s, 0) + x;
            ans = max(ans, s);
        }
        return ans;
    }
};
```



