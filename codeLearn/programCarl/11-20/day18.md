##  day18 今日任务4.20

1. 513.找树左下角的值

2. 112.路径总和  

3. 113.路径总和ii

5. 106.从中序与后序遍历序列构造二叉树

6. 105.从前序与中序遍历序列构造二叉树

   

#### 513.找树左下角的值

[力扣题目链接](https://leetcode.cn/problems/find-bottom-left-tree-value/)

// 找最后一排最左边那个数

// 迭代法, 使用层序遍历  但从右到左

```cpp
// 迭代法 层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode *node;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        return node->val;
    }
};
```

// 递归法 寻找深度最大的第一个元素 需要一个量记录遍历过的最大深度，如果当前深度大于最大深度，则更新该值

```cpp
// 递归法
class Solution {
private:
    int m_depth = 0;
    int result = 0;
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        depth++;
        if (depth > m_depth) {
            m_depth = depth;
            result = node->val;
        }
        dfs(node->left, depth);
        dfs(node->right, depth);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};

```



####  112. 路径总和

[力扣题目链接](https://leetcode.cn/problems/path-sum/)



```cpp
class Solution {
private:
    bool result = false;
    void traversal(TreeNode* node, int targetSum, int sum) {
        sum += node->val;
        if (node->left == node->right && sum == targetSum) {
            result = true;
            return;
        }
        if (node->left) traversal(node->left, targetSum, sum);
        if (node->right) traversal(node->right, targetSum, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return result;
        traversal(root, targetSum, 0);
        return result;


    }
};

```

#### 113.路径之和II

[力扣题目链接](https://leetcode.cn/problems/path-sum-ii/)

// 回溯

```cpp
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(TreeNode* node, int targetSum) {
        path.emplace_back(node->val);
        if (node->left == node->right && targetSum - node->val == 0) {
            result.emplace_back(path);
            return;
        }
        if (node->left)  {
            traversal(node->left, targetSum - node->val);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, targetSum - node->val);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return{};
        traversal(root, targetSum);
        return result;
    }
};
```



#### 106.从中序与后序遍历序列构造二叉树

[力扣题目链接](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

主要思路：

1. 后续数组为0，则为空节点
2. 后序数组最后一个元素为节点元素
3. 寻找中序数组位置作为切割点
4. 切分中序数组
5. 切分后序数组
6. 递归处理左区间和右区间

```cpp
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) { // 空节点
            return nullptr;
        }
        int left_size = ranges::find(inorder, postorder.back()) - inorder.begin(); // 左子树的大小
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + left_size + 1, inorder.end());
        vector<int> post1(postorder.begin(), postorder.begin() + left_size);
        vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
        TreeNode *left = buildTree(in1, post1);
        TreeNode *right = buildTree(in2, post2);
        return new TreeNode(postorder.back(), left, right);
    }
};


```

```cpp
// 优化
// 1.用一个哈希表（或者数组）预处理 inorder 每个元素的下标，这样就可以 O(1)查到 postorder[n−1]在 inorder 的位置，从而 O(1)知道左子树的大小。
// 2.把递归参数改成子数组下标区间（左闭右开区间）的左右端点，从而避免复制数组。
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int in_l, int in_r, int post_l, int post_r) -> TreeNode* {
            if (post_l == post_r) { // 空节点
                return nullptr;
            }
            int left_size = index[postorder[post_r - 1]] - in_l; // 左子树的大小
            TreeNode *left = dfs(in_l, in_l + left_size, post_l, post_l + left_size);
            TreeNode *right = dfs(in_l + left_size + 1, in_r, post_l + left_size, post_r - 1);
            return new TreeNode(postorder[post_r - 1], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};
```



#### 105.从前序与中序遍历序列构造二叉树

[力扣题目链接](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

```cpp
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            int left_size = index[preorder[pre_l]] - in_l; // 左子树的大小
            TreeNode *left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode *right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};

```

