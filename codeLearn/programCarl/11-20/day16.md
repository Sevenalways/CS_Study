##  day16 今日任务4.18

1. 104.二叉树的最大深度 
2. 559.n叉树的最大深度
3. 111.二叉树的最小深度
4. 222.完全二叉树的节点个数

#### 104.二叉树的最大深度

[力扣题目链接](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

// 前序遍历 自顶向下 求的深度

```cpp
class Solution {
private:
    int ans = 0;
    void dfs(TreeNode* node, int cnt) {
        if (node == nullptr) return;
        cnt++;
        ans = max(ans,cnt);
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```

// 后序遍历 自底向上 求的高度

```cpp
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }
};
```



- [559.n叉树的最大深度(opens new window)](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/)

```cpp
class Solution {
    private:
    int ans = 0;
    void dfs(Node* node, int cnt) {
        if (node == nullptr) return;
        cnt++;
        ans = max(ans,cnt);
        for (auto c : node->children) {
            dfs(c, cnt);
        }
    }
public:
    int maxDepth(Node* root) {
        dfs(root, 0);
        return ans;   
    }
};

```



#### 111.二叉树的最小深度

[力扣题目链接](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

```cpp
// 前序遍历 求深度
class Solution {
    int ans = INT_MAX;

    void dfs(TreeNode *node, int cnt) {
        if (node == nullptr) {
            return;
        }
        cnt++;
        if (node->left == node->right) { // node 是叶子
            ans = min(ans, cnt);
            return;
        }
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    };

public:
    int minDepth(TreeNode *root) {
        dfs(root, 0);
        return root ? ans : 0;
    }
};


// 前序优化
class Solution {
    int ans = INT_MAX;

    void dfs(TreeNode *node, int cnt) {
        if (node == nullptr || ++cnt >= ans) {
            return;
        }
        if (node->left == node->right) { // node 是叶子
            ans = cnt;
            return;
        }
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    };

public:
    int minDepth(TreeNode *root) {
        dfs(root, 0);
        return root ? ans : 0;
    }
};

```

```cpp
// 后序遍历
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```



#### 222.完全二叉树的节点个数

[力扣题目链接](https://leetcode.cn/problems/count-complete-tree-nodes/)

```cpp
// 普通二叉树的节点个数
// 前序遍历
class Solution {
private:
    int ans = 0;
    void dfs (TreeNode* node, int &cnt) {
        if (node == nullptr) return;
        cnt++;
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    }
public:
    int countNodes(TreeNode* root) {
        dfs(root, ans);
        return ans;
    }
};


// 后序遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

```

```cpp
// 利用完全二叉树的性质
```

```cpp

class Solution {
private:
    int getcount(TreeNode* root) {
        if (root == nullptr) return 0;
        auto left = root->left, right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right)
        {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) return (2 << leftDepth) - 1;
        return getcount(root->left) + getcount(root->right) + 1;
        
    }
public:
    int countNodes(TreeNode* root) {
        return getcount(root);
    }
};
```

