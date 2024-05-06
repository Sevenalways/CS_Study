##  day23 今日任务4.25

1. 669.修剪二叉搜索树

2. 108.将有序数组转化为二叉搜索树

3. 538.把二叉搜索树转换为累加数

   

####  669. 修剪二叉搜索树

[力扣题目链接](https://leetcode.cn/problems/trim-a-binary-search-tree/)

// 迭代

```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

```

// 递归

```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root != nullptr && (root->val < L || root->val > R)) {
            if (root->val < L) root = root->right; // 小于L往右走
            else root = root->left; // 大于R往左走
        }
        TreeNode *cur = root;
        // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
        while (cur != nullptr) {
            while (cur->left && cur->left->val < L) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;

        // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
        while (cur != nullptr) {
            while (cur->right && cur->right->val > R) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};


```

#### 108.将有序数组转换为二叉搜索树

[力扣题目链接](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

```cpp
class Solution {
private:
     TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (right == left) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, left, mid);
        node->right = dfs(nums, mid + 1, right);
        return node;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};
```

#### 538.把二叉搜索树转换为累加树

[力扣题目链接](https://leetcode.cn/problems/convert-bst-to-greater-tree/)

```cpp
class Solution {
    private:
    void dfs(TreeNode* node, int &sum) {
        if (node == nullptr) return;
        dfs(node->right, sum);
        sum += node->val;
        node->val = sum;
        dfs(node->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};


class Solution {
private:
    int sum = 0;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {

        dfs(root);
        return root;
    }
};

```



