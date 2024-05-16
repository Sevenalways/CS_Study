## day38 今日任务5.13

1.  动态规划理论基础
2.  509.斐波那契数列
3.  70.爬楼梯
4.  746.使用最小花费爬楼梯

#### 动态规划理论基础

对于动态规划问题，拆解为如下五步曲，

1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组



#### 509.斐波那契数列

[力扣题目链接](https://leetcode.cn/problems/fibonacci-number/)

```cpp
class Solution {
public:
    int fib(int n) {
        int f = 1, g = 0;// 分别表示fib(-1),fib(0)
        while(0 < n--) {
            g += f;
            f = g - f;
        }
        return g;//fib(n)
    }
};
```

#### 70. 爬楼梯

[力扣题目链接](https://leetcode.cn/problems/climbing-stairs/)

本题可转化为 **求斐波那契数列的第 n 项**，区别仅在于初始值不同：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int f = 0, g = 1;// 分别表示fib(-1),fib(0)
        while(0 < n--) {
            g += f;
            f = g - f;
        }
        return g;//fib(n)
    }
};

```

#### 746. 使用最小花费爬楼梯

[力扣题目链接](https://leetcode.cn/problems/min-cost-climbing-stairs/)

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int pre = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            int next = min(cur + cost[i - 1], pre + cost[i - 2]);
            pre = cur;
            cur = next;
        }
        return cur;
    }
};

```

