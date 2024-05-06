##  day20 今日任务4.22

1. 654.最大二叉树

2. 617.合并二叉树

3. 700.二叉搜索树中的搜索

4. 98.验证二叉搜索树

   

#### 654.最大二叉树

[力扣题目地址](https://leetcode.cn/problems/maximum-binary-tree/)

// 方法1 递归

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums.front());

        int index = ranges::max_element(nums.begin(), nums.end()) - nums.begin();
        vector<int> l(nums.begin(), nums.begin() + index);
        vector<int> r(nums.begin() + index + 1, nums.end());

        auto *left = constructMaximumBinaryTree(l);
        auto *right = constructMaximumBinaryTree(r);
        return new TreeNode(nums[index], left, right);
    }
};
```

// 方法1 优化 传递区间

```cpp
class Solution {
private:
    TreeNode* construct(const vector<int>& nums, int left, int right) {
        if (left == right) return nullptr;
        int best = ranges::max_element(nums.begin() + left, nums.begin() + right) - nums.begin();
        auto *l = construct(nums, left, best);
        auto *r = construct(nums, best + 1, right);
        return new TreeNode(nums[best], l, r);
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};
```

// 方法2 单调栈

```cpp



```



####  617.合并二叉树

[力扣题目链接](https://leetcode.cn/problems/merge-two-binary-trees/)

分类讨论

1. 如果root1为空，直接返回root2
2. 如果root2为空，直接返回root1
3. 如果都不为空，将两个节点的值相加，作为合并后节点的新值。然后递归合并左子树和右子树。

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        auto *left = mergeTrees(root1->left, root2->left);
        auto *right = mergeTrees(root1->right,root2->right);
        return new TreeNode(root1->val + root2->val, left, right);

    }
};
```

####  700.二叉搜索树中的搜索

[力扣题目地址](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (val == root->val) return root;
        if (val > root->val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};


```



#### 98.验证二叉搜索树

[力扣题目链接](https://leetcode.cn/problems/validate-binary-search-tree/)

// 前序遍历

```cpp
class Solution {
public:
    bool isValidBST(TreeNode *root, long left = LONG_MIN, long right = LONG_MAX) {
        if (root == nullptr) return true;
        long x = root->val;
        return x > left && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right); 
    }
};
```

// 中序遍历

```cpp
class Solution {
    long pre = LONG_MIN;
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left) || root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
```

```cpp
class Solution {
    pair<long, long> dfs(TreeNode *node) {
        if (node == nullptr)
            return {LONG_MAX, LONG_MIN};
        auto[l_min, l_max] = dfs(node->left);
        auto[r_min, r_max] = dfs(node->right);
        long x = node->val;
        // 也可以在递归完左子树之后立刻判断，如果发现不是二叉搜索树，就不用递归右子树了
        if (x <= l_max || x >= r_min)
            return {LONG_MIN, LONG_MAX};
        return {min(l_min, x), max(r_max, x)};
    }

public:
    bool isValidBST(TreeNode *root) {
        return dfs(root).second != LONG_MAX;
    }
};

```

