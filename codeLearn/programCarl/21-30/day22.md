##  day22 今日任务4.24

1. 235.二叉搜索树的最近公共祖先

2. 701.二叉搜索树中的插入操作

3. 450.删除二叉搜索树中的节点

   

####  235. 二叉搜索树的最近公共祖先

[力扣题目链接](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root -> val;
        if (p->val < x && q->val < x) return lowestCommonAncestor(root->left, p, q);
        if (p->val > x && q->val > x) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
```

#### 701.二叉搜索树中的插入操作

[力扣题目链接](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val > root-val) root->left = insertIntoBST(root->right, val);
        else root->right = insertIntoBST(node->left, val);
        return root;
    }
};
```

####  450.删除二叉搜索树中的节点

[力扣题目链接](https://leetcode.cn/problems/delete-node-in-a-bst/)

分类讨论

1. 查找该节点
2. 没有找到->
3. 找到了
   - 叶子结点
   - 只有左孩子
   - 只有右孩子
   - 左右孩子都有



移除元素：递归法中，将待删除的节点的子节点接入其父节点，即将子节点返回给上一层调用

```cpp
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;// 没找到
        if (root->val == key) {// 找到了
            if (root->left == root->right) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            } else if (root->right == nullptr) {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            } else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temp = root->right;
                delete root;
                return temp; 
            }
        }
        if (key > root->val) root->right = deleteNode(root->right, key);
        if (key < root->val) root->left = deleteNode(root->left, key);
        return root;
    }
};

```



```cpp
//迭代
class Solution {
private:
    TreeNode* deleteOneNode(TreeNode* node) {
        if (node == nullptr) return nullptr;
        if (node->right == nullptr)  return node->left;
        TreeNode* cur = node->right;
        while (cur->left)
        {
            cur = cur->left;
        }
        cur->left = node->left;
        return node->right;       
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while(cur && cur->val != key) {
            if (key > cur->val) {
                pre = cur;
                cur = cur->right;
            } else if (key < cur->val) {
                pre = cur;
                cur = cur->left;
            }
        }
        if (pre == nullptr) return deleteOneNode(cur);
        if (pre->left && pre->left->val == key) pre->left = deleteOneNode(cur);
        if (pre->right && pre->right->val == key) pre->right = deleteOneNode(cur);
        return root;
    }
};
```



