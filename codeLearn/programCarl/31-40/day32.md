##  day32 今日任务5.7

1. 122.买卖股票的最佳时机II
2. 55.跳跃游戏
3. 45.跳跃游戏II



#### 122.买卖股票的最佳时机 II

[力扣题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

```CPP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};


```

#### 55. 跳跃游戏

[力扣题目链接](https://leetcode.cn/problems/jump-game/)

```CPP
// 从最后开始往前跳，遇到0检查前面是否能有跳过该处的能力
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return true;
        int count = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                count++;
            } else {
                count = nums[i] > count ? 0 : (count + 1);
            }
        }
        return count == 0;
    }
};
```
```CPP
// 从前往后跳，依次判断能跳的最远处
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i > k)
                return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
```

#### 45.跳跃游戏 II

[力扣题目链接](https://leetcode.cn/problems/jump-game-ii/)

```CPP
// 从后往前 每次选择最远的位置 时间复杂度0(n2)
class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int ans = 0;
        while (pos > 0) {
            for (int i = 0; i < pos; i++) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```

```cpp
// 正向查找 贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur = 0; // 当前步的范围
        int nxt = 0; // 下一步的范围
        for (int i = 0; i < nums.size() - 1; i++) {
            nxt = max(nums[i] + i, nxt);
            if (i == cur) {
                ans++;
                cur = nxt;
            }
        }
        return ans;
    }
};

```



