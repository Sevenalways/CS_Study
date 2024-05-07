##  day33 今日任务5.8

1.  1005 K次取反后最大化的数组和
2. 134.加油站
3. 135.分发糖果



####  1005. K次取反后最大化的数组和

[力扣题目链接](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

依次选取最小的数反转

```CPP
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] > 0 ) {
            return accumulate(nums.begin(), nums.end(), k % 2 == 0 ? 0 : -2 * nums[0]);
        }
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -1 * nums[i];
                k--;
                count++;
            }
            sum += nums[i];
        }
        if (count == n)
            sum -= k % 2 == 0 ? 0 : 2 * nums[n - 1];
        else sum -= k % 2 == 0 ? 0 : 2 * min(nums[count - 1], nums[count]);
        return sum;
         
    }
};
```

####  135. 分发糖果

[力扣题目链接](https://leetcode.cn/problems/candy/)

```CPP
class Solution {
public:
    // 左右两次遍历
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int right = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ans += max(left[i], right);
        }
        return ans + left[n - 1];
    }
};
```
```CPP
class Solution {
public:
    // 一次便利，依次记录上升下降区间
    // 若上升，则加1，若下降 则区间所有都加1
    int candy(vector<int>& ratings) {
        int ans = 1;
        int n = ratings.size();
        int inc = 1, dec = 0;
        int num = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i -1]) {
                dec = 0;
                num = ratings[i] == ratings[i - 1] ? 1 : num + 1;
                ans += num;
                inc = num;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ans += dec;
                num = 1;
            }
        }
        return ans;
    }
};
```

#### 134. 加油站

[力扣题目链接](https://leetcode.cn/problems/gas-station/)

```CPP
class Solution {
public:
    // 遍历累加各站剩余油量，将累计亏损最大的一段作为最后一段
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int spare = 0, minSpare = 1E5;
        for (int i = 0; i < n; i++) {
            spare += gas[i] - cost[i];
            if (spare < minSpare) {
                minSpare = spare;
                ans = i + 1;//将累计亏损最大的一段作为最后一段
            }
        }
        if (minSpare >= 0) return 0; // 如果最小剩余量都大于0，则任意起点都可以
        return spare >= 0 ? ans %  n : -1;
    }
};
```

```cpp
class Solution {
public:
    // 局部最优：当前累加rest[i]的和curSum一旦小于0，起始位置至少要是i+1，
    // 因为从i之前开始一定不行。
    // 全局最优：找到可以跑一圈的起始位置。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};
```

