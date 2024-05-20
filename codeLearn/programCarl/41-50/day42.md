## day42 今日任务5.17

1. 1049.最后一块石头的重量II

2. 494.目标和

3. 474.一和零

   

####  1049.最后一块石头的重量II

[力扣题目链接](https://leetcode.cn/problems/last-stone-weight-ii/)

**key：**让石头尽量分成重量相等的两堆，相撞后，剩下的石头质量最小，类似于[416.分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)

```cpp
class Solution {
public:
    //key：让石头尽量分成重量相等的两堆，相撞后，剩下的石头质量最小，类似于416.分割等和子集
    // dp[j] 表示不超过j的容量可以达到的最大值
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        
        for (int stone : stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - 2 * dp[target];
    }
};
```



####  494.目标和

[力扣题目链接](https://leetcode.cn/problems/target-sum/)

```cpp
class Solution {
public:
    // 正数和为p，负数为s-p，则有 p - (s - p) = target,即 p = (s + t)/ 2
    // 2 1:1翻译为递推
    int findTargetSumWays(vector<int>& nums, int target) {
        target += reduce(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

        int n = nums.size(), f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for(int c = 0; c <= target; c++) {
                if (c < nums[i]) f[i + 1][c] = f[i][c];
                else f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
            }
        }
        return f[n][target];
    }
};
```



```cpp
class Solution {
public:
    // 正数和为p，负数为s-p，则有 p - (s - p) = target,即 p = (s + t)/ 2
    // 方法4 空间优化：一个数组
    //  ！！！！！从右往左计算
    int findTargetSumWays(vector<int>& nums, int target) {
        target += reduce(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

       vector<int> f(target + 1, 0);
       f[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int c = target; c >= nums[i]; c--) {// 从右往左
                f[c] += f[c - nums[i]];
            }
        }
        return f[target];
    }
};
```

#### 474.一和零

[力扣题目链接](https://leetcode.cn/problems/ones-and-zeroes/)

```cpp
class Solution {
public:
    // 01背包 至多capacity 求最大值
    // 方法1 递归
    // dfs(i, zero, one) = max(dfs(i-1, zero, one), dfs(i-1, zero - count[0], one - count[1]) + 1)
    int countZero(string & s) {    
        return count(s.begin(), s.end(), '0');
    }
    int findMaxForm(vector<string>& strs, int m, int n) {// m = zero, n = one
        unordered_map<long long, int> memo;
        int len = strs.size();

        function<int(int, int, int)> dfs = [&](int i, int zero, int one) {
            //if (i < 0) return zero >= 0 && one >= 0 ? 0 : INT_MIN;
            if (i < 0) return 0;// 由于下面已经处理了，所以此处直接返回0即可
            long long key = ((long long) i << 32) | (zero << 16) | one;
            if (memo.count(key)) return memo[key];

            int count0 = countZero(strs[i]), count1 = strs[i].size() - count0;
            if (zero >= count0 && one >= count1) 
                return memo[key] = max(dfs(i - 1, zero, one), dfs(i - 1, zero - count0, one - count1) + 1);
            return memo[key] = dfs(i - 1, zero, one);
            
        };
        return dfs(len - 1, m, n);
    }
};
```

```cpp
class Solution {
public:
    // 01背包 至多capacity 求最大值
    // 方法2 翻译为递推
    // dfs(i, zero, one) = max(dfs(i-1, zero, one), dfs(i-1, zero - count[0], one - count[1]) + 1)
    int countZero(string & s) {    
        return count(s.begin(), s.end(), '0');
    }
    int findMaxForm(vector<string>& strs, int m, int n) {// m = zero, n = one
        int len = strs.size();
        int f[len + 1][m + 1][n + 1];
        memset(f, 0, sizeof(f));
        //f[0][0][0] = 0;
        for (int i = 0; i < len; i++) {
            int count0 = countZero(strs[i]), count1 = strs[i].size() - count0;
            for (int zero = 0; zero <= m; zero++) {
                for (int one = 0; one <= n; one++) {
                    if (zero >= count0 && one >= count1) 
                        f[i + 1][zero][one] = max(f[i][zero][one], f[i][zero - count0][one - count1] + 1);
                    else
                         f[i + 1][zero][one] = f[i][zero][one];
                }
            }
        }
        return f[len][m][n];
    }
};
```

```cpp
class Solution {
public:
    // 01背包 至多capacity 求最大值
    // 方法3 空间优化
    // dfs(i, zero, one) = max(dfs(i-1, zero, one), dfs(i-1, zero - count[0], one - count[1]) + 1)
    int countZero(string & s) {    
        return count(s.begin(), s.end(), '0');
    }
    int findMaxForm(vector<string>& strs, int m, int n) {// m = zero, n = one
        int len = strs.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < len; i++) {
            int count0 = countZero(strs[i]), count1 = strs[i].size() - count0;
            for (int zero = m; zero >= count0; zero--) {
                for (int one = n; one >= count1; one--) {
                        f[zero][one] = max(f[zero][one], f[zero - count0][one - count1] + 1);
                }
            }
        }
        return f[m][n];
    }
};
```

