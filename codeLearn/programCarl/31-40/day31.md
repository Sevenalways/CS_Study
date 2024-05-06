##  day31 今日任务5.6

1. 455.分发饼干

2. 376.摆动序列

3. 53.最大子序和

   

#### 455.分发饼干

[力扣题目链接](https://leetcode.cn/problems/assign-cookies/)

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int len1 = g.size(), len2 = s.size();
        int ans = 0;
        for (int i = 0, j = 0; i < len1 && j < len2; i++, j++) {
            while (j < len2 && g[i] > s[j]) {
                j++;
            }
            if (j < len2) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### 376. 摆动序列

[力扣题目链接](https://leetcode.cn/problems/wiggle-subsequence/)

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int ans = 0;
        int pre = 0;
        int cur = 0;
        for (int i = 1; i < n; i++) {
            cur = nums[i] - nums[i - 1];
            if ((pre <= 0 && cur > 0) || (pre >= 0 && cur < 0)) {
                ans++;
                pre = cur;
            }
        }
        return ++ans;
    }
};
```

#### 53. 最大子序和

[力扣题目链接](https://leetcode.cn/problems/maximum-subarray/)

```cpp
// 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            } 
        }
        return ans;
    }
};

```

```cpp
// 最小前缀和
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum = 0;
        for (int x : nums) {
            pre_sum += x; // 当前的前缀和
            ans = max(ans, pre_sum - min_pre_sum); // 减去前缀和的最小值
            min_pre_sum = min(min_pre_sum, pre_sum); // 维护前缀和的最小值
        }
        return ans;
    }
};

```



