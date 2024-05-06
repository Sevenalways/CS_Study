##  day21 今日任务4.23

1. 530.二叉搜索树的最小绝对差

2. 501.二叉搜索树中的众数 

3. 236.二叉树的最近公共祖先

   

#### 530.二叉搜索树的最小绝对差

[力扣题目链接](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

```cpp
class Solution {
private:
    int result = 1e6;
    int pre = -1e6; 
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        result = min(node->val - pre, result);
        pre = node->val;
        dfs(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return result;
    }
};
```

####  501.二叉搜索树中的众数

[力扣题目链接](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)

```cpp
class Solution {
public:
    vector<int> ans;
    int base, count, maxCount;
    void update (int x) {
        if (x == base) {
            count++;
        }else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            ans.emplace_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.emplace_back(base);
        }
    }
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        update(node->val);
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

#### 236. 二叉树的最近公共祖先

[力扣题目链接](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

![image-20240503003845252](C:/Users/Seven/AppData/Roaming/Typora/typora-user-images/image-20240503003845252.png)

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
       if (node == nullptr || node == p || node == q) {
           return node;
       }
       auto l = lowestCommonAncestor(node->left, p, q);
       auto r = lowestCommonAncestor(node->right, p, q);
       return (l && r) ? node : (l ? l : r);
    }
};
```



