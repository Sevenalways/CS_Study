##  day15 今日任务4.17

1. 102.二叉树的层序遍历
2. 226.翻转二叉树
3. 101.对称二叉树

#### 102.二叉树的层序遍历

[力扣题目链接](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

层序遍历，又称为二叉树的**广度优先搜索(BFS)**。BFS通常借助**队列**的**先入先出**特性来实现。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            for (int n = q.size(); n--;) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.emplace_back(vals);
        }
        return ans;
    }
};
```



#### 226.翻转二叉树

[力扣题目链接](https://leetcode.cn/problems/invert-binary-tree/)

后序遍历

```cpp
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto left = invertTree(root->left); // 翻转左子树
        auto right = invertTree(root->right); // 翻转右子树
        root->left = right; // 交换左右儿子
        root->right = left;
        return root;
    }
};
```

#### 101.对称二叉树

[力扣题目链接](https://leetcode.cn/problems/symmetric-tree/)

后序遍历

```cpp
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if  (p == nullptr || q == nullptr)
            return p == q;
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSameTree(root->left, root->right);
    }
};

```

