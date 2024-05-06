



##  day14 今日任务 4.16

1. 理论基础
2. 递归遍历（前中后序 层序）
3. 迭代遍历（前中后序 层序）
4. 统一迭代



#### 递归算法三部曲

1. 确定递归函数的参数和返回值
2. 确定终止条件
3. 确定递归单层调用逻辑

#### 2.递归遍历：144 145 94

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
public:
    void preTraversal(TreeNode* cur, vector<int> &ans) {
            if (cur == nullptr) return;
            ans.push_back(cur->val);
            preTraversal(cur->left, ans);
            preTraversal(cur->right, ans);
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preTraversal(root,ans);
        return ans;
    }
};
```

#### 迭代遍历1

递归：每一次递归调用会把函数的局部变量，参数值和返回值等压入**调用栈**，然后在结束本次递归操作时，从栈顶弹出上一次递归的各项参数。

利用**栈**实现二叉树迭代遍历

**前序遍历**，每次先处理中间结点，先将根节点入栈，再将右孩子入栈，最后左孩子入栈

出栈顺序为：中->左->右，故入栈顺序为中->右->左

```cpp
class Solution {
public:
    void preTraversal(TreeNode* cur, vector<int> &ans) {
            if (cur == nullptr) return;
            ans.push_back(cur->val);
            preTraversal(cur->left, ans);
            preTraversal(cur->right, ans);
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preTraversal(root,ans);
        return ans;
    }
};
```

**中序遍历**，处理顺序为：左->中->右，先访问的是二叉树顶部的节点，然后一层一层的向下，直到到达树左边的底部，再开始处理节点，这就导致了处理顺序和读取顺序不一致

在处理中序遍历时，需要借助**指针的遍历**来访问节点，利用**栈**处理节点上的数据。

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack(TreeNode*) st;
        vector<int> ans;

        st.push_back(root);
        while (!st.empty)
        {
            TreeNode* node = st.top(); // 中
            st.pop();
            ans.push_back(node->val);
            if (node->right) st.push(node->right); // 右
            if (node->left) st.push(node->left);   // 左
        }
        return ans;
    }
};
```

**后序遍历**，处理顺序为：左->右->中，可以利用前序遍历的方法，处理为：中->右->左，再反转

```cpp
class Solution {
public:
// 后
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode*> st; 
        vector<int> ans;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node>right);

        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

```

#### 迭代遍历2

// **前序遍历**

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node != nullptr ||!stk.empty()) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};
```

// **中序遍历**

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

```



// **后序遍历**

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};
```

#### 统一迭代

**key：**将要访问的节点入栈，将要处理的节点也放入栈中但是要做**标记**:**即**将要处理的节点放入栈中后，紧接着放入一个**空指针**作为**标记**。这种方法也称为标记法。

**前序遍历**

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack(TreeNode*) st;
        vector<int> res;
        if (root == nullptr) {
            return res;
        } else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right) st.push(node->right);// 右
                if (node->left) st.push(node->left);// 左
                st.push(node);// 中
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }

        }
        return res;
    }
};
```

**中序遍历**

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack(TreeNode*) st;
        vector<int> res;
        if (root == nullptr) {
            return res;
        } else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right) st.push(node->right);// 右
                st.push(node);// 中
                st.push(nullptr);
                if (node->left) st.push(node->left);// 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }

        }
        return res;
    }
};
```

**后序遍历**

```cpp
class Solution {
public:
    vector<int> postrderTraversal(TreeNode* root) {
        stack(TreeNode*) st;
        vector<int> res;
        if (root == nullptr) {
            return res;
        } else st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node) {
                st.pop();
                if (node->right) st.push(node->right);// 右
                st.push(node);// 中
                st.push(nullptr);
                if (node->left) st.push(node->left);// 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }

        }
        return res;
    }
};

```



