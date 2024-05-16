## day36 今日任务5.11

1.  738.单调递增的数字
2.  968.监控二叉树

#### 738.单调递增的数字

[力扣题目链接](https://leetcode.cn/problems/monotone-increasing-digits/)

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strN = to_string(n);
        int i = 1;
        while (i < strN.length() && strN[i - 1] <= strN[i]) {
            i += 1;
        }
        if (i < strN.length()) {
            while (i > 0 && strN[i - 1] > strN[i]) {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for (i += 1; i < strN.length(); ++i) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};

```

#### 968.监控二叉树

[力扣题目链接](https://leetcode.cn/problems/binary-tree-cameras/)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    tuple<int, int, int> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {INT_MAX / 2, 0, 0}; // 除 2 防止加法溢出
        }
        auto [l_choose, l_by_fa, l_by_children] = dfs(node->left);
        auto [r_choose, r_by_fa, r_by_children] = dfs(node->right);
        int choose = min(l_choose, l_by_fa) + min(r_choose, r_by_fa) + 1;
        int by_fa = min(l_choose, l_by_children) + min(r_choose, r_by_children);
        int by_children = min({l_choose + r_by_children, l_by_children + r_choose, l_choose + r_choose});
        return {choose, by_fa, by_children};
    }

public:
    int minCameraCover(TreeNode *root) {
        auto [choose, _, by_children] = dfs(root);
        return min(choose, by_children);
    }
};

```

