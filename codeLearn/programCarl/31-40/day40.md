## day40 今日任务5.15

1.  343.整数拆分
2.  96.不同的二叉搜索树

####  343. 整数拆分

[力扣题目链接](https://leetcode.cn/problems/integer-break/)

方法1：纯暴力数学

```cpp
class Solution {
public:
    int product(int n, int k) {
        int result = 1;
        int count = n % k;
        int num = n / k;
        for (int i = 0; i < count; i++) {
            result *= num + 1;
        }
        for (int i = 0; i < k - count; i++) {
            result *= num;
        }
        return result;
    }
    int integerBreak(int n) {
        int ans = 0;
        for (int k = 2; k <= n / 3 + 2; k++) {// 原写的是k <= n，后根据方法2，调整为n / 3 + 2
            ans = max(ans, product(n, k));
        }
        return ans;
    }
};

```

方法2 ：方法1优化，最好结果按照3进行划分，即n = 3a + b，当b = 0， 1， 2时返回不同结果

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0)
            return (int)pow(3, a);
        if (b == 1)
            return (int)pow(3, a - 1) * 4;
        else
            return (int)pow(3, a) * 2;
    }
};
```

方法3：动态规划

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
```



#### 96.不同的二叉搜索树

[力扣题目链接](https://leetcode.cn/problems/unique-binary-search-trees/)

方法1：动态规划，

假设dp[i]表示i个节点构成的二叉搜索树的个数，f(i)表示以i为根的二叉搜索树，则

dp[i] = f(1) + f(2) + ... +f(n)

且f(i) = dp(i - 1) * dp(n - i)

因此dp[n] = dp[0] *dp[n - 1] +  dp[1] *dp[n - 2] +...+  dp[n - 1] *dp[0]

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```

方法2：卡特兰数公式

方法1中的公式为卡特兰数，其计算公式如下

```cpp
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
```

