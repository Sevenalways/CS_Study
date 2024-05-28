## day52 今日任务5.27

1. 300.最长递增子序列
2. 674.最长连续递增序列
3. 718.最长重复子数组



#### 300.最长递增子序列

[力扣题目链接](https://leetcode.cn/problems/longest-increasing-subsequence/)

```cpp
class Solution {
public:
    // 动态规划
    // dfs(i) 表示以 nums[i] 结尾的最长递增子序列（LIS）的长度。
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return n;
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > ans) ans = dp[i];  
        }
        return ans;
    }
};
```

```cpp
class Solution {
public:
    // 贪心+二分
    int lengthOfLIS(vector<int> &nums) {
        vector<int> g;
        for (int x : nums) {
            auto it = ranges::lower_bound(g, x);
            if (it == g.end()) {
                g.push_back(x); // >=x 的 g[j] 不存在
            } else {
                *it = x;
            }
        }
        return g.size();
    }
};
```





####  674. 最长连续递增序列

[力扣题目链接](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)



```cpp
class Solution {
public:
    // df[i] 表示以nums[i]结尾的最长连续递增子序列(LCIS)的长度
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

```cpp
class Solution {
public:
    // 空间优化
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int ans = 0, count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) count++;
            else count = 1;
            ans = max(ans, count);
        }
        return ans;
    }
};
```



#### 718. 最长重复子数组

[力扣题目链接](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/)

```cpp
class Solution {
public:
    // dp[i + 1][j + 1]表示nums1 和nums2中以nums1[i]和nums[j]结尾的公共最长子数组的长度
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = 0;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};
```



```cpp
class Solution {
public:
    // dp[i + 1][j + 1]表示nums1 和nums2中以nums1[i]和nums[j]结尾的公共最长子数组的长度
    // 空间优化为一维
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {// 从后往前
                if (nums1[i] == nums2[j]) dp[j + 1] = dp[j] + 1;
                else dp[j + 1] = 0;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans;
    }
};
```



