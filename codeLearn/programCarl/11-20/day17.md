##  day17 今日任务4.19

1. 110.平衡二叉树
2. 257.二叉树的所有路径
3. 404.左叶子之和

#### 110.平衡二叉树

[力扣题目链接](https://leetcode.cn/problems/balanced-binary-tree/)

```cpp
class Solution {
public:
    int get_height(TreeNode * node) {
        if (node == nullptr) return 0;
        int l_hieght = get_height(node -> left);
        if (l_hieght == -1) return -1;
        int r_hieght = get_height(node -> right);
        if (r_hieght == -1 || abs(l_hieght - r_hieght) > 1) return -1;
        return max(l_hieght, r_hieght) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1; 

    }
};
```



####  257. 二叉树的所有路径

[力扣题目链接](https://leetcode.cn/problems/binary-tree-paths/)



```cpp
class Solution {
private:

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result); // 左
        if (cur->right) traversal(cur->right, path + "->", result); // 右
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) return result;
        traversal(root, path, result);
        return result;

    }
};
```

#### 404.左叶子之和

[力扣题目链接](https://leetcode.cn/problems/sum-of-left-leaves/)

// 后序遍历

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right== nullptr) return 0;

        int leftValue = sumOfLeftLeaves(root->left);   // 左
        if (root->left && !root->left->left && !root->left->right) { // 左叶子结点
            leftValue = root->left->val;
        }
        return leftValue + sumOfLeftLeaves(root->right);                
    }
};

```

