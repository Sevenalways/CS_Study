## day47 今日任务5.22

1. 198.打家劫舍
2. 213.打家劫舍II
3. 337.打家劫舍III

#### 198.打家劫舍

[力扣题目链接](https://leetcode.cn/problems/house-robber/)

```cpp
class Solution {
public:
    // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    // dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n + 2, 0);
        for (int i = 0; i < n; ++i)
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        return f[n + 1];
    }
};
```





#### 213.打家劫舍II

[力扣题目链接](https://leetcode.cn/problems/house-robber-ii/)

```cpp
class Solution {
public:
    // 198.打家劫舍
    int rob1(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            int f = max (f1, f0 + nums[i]);
            f0 = f1;
            f1 = f;
        }
        return f1;
    }
    int rob(vector<int> &nums) {
        int n = nums.size();
        // 第0间偷或者不偷 区间[start, end)
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
    }
};
```

####  337.打家劫舍 III

[力扣题目链接](https://leetcode.cn/problems/house-robber-iii/)

**后序遍历，因为通过递归函数的返回值来做下一步计算**。

```cpp
class Solution {
public:
    // dp(root) = max(dp(root->left) + dp(root->right), root->val + dp(root.孙子))
    // 方法1 记忆化搜索
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;
            if (node->left == nullptr && node->right == nullptr) return node->val;
            if (memo.find(node) != memo.end()) return memo[node];
            // 偷父节点
            int val1 = node->val;
            if (node->left) val1 += dfs(node->left->left) + dfs(node->left->right);
            if (node->right) val1 += dfs(node->right->left) + dfs(node->right->right);

            //不偷父节点
            int val2 = dfs(node->left) + dfs(node->right);
            return memo[node] = max(val1, val2); 
        };
        return dfs(root);
    }
};

```

方法2 ：数形DP入门题

方法1没有记录当前偷与不偷得到的最大金额，而动态规划其实就是使用状态转移方程来记录状态的变化

定义dp[2]：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL)
            return vector<int>{0, 0}; // 偷不偷都是0
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，那么就不能偷左右节点。
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur，那么左右节点可以偷也可以不偷，取较大的情况
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};
```

