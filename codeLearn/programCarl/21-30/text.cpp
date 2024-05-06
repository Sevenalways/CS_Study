// day 21

//501 
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
            ans.empalce_back(base);
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

// day 22
// 450 删除二叉搜索树的节点
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
        if (key > root->val) root->right = deleteNode(root->val, key);
        if (key < root->val) root->right = deleteNode(root->left, key);
        return root;
    }
};

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


// day 24
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int i, int k) {
        int d = k - path.size();
        if (d == 0) {
            ans.emplace_back(path);
            return;
        }
        for (int j = i; j >= d; --j) {
            path.push_back(j);
            dfs(j - 1, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        dfs(n, k);
        return ans;
    }
};

// day 25
class Solution {
    // 输入的角度：以此枚举选择
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > (2 * i - d + 1) * d / 2) return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= d; --j) {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
};

class Solution {
    // 答案的角度 ：选不选这个数
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > (2 * i - d + 1) * d / 2) return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            // 不选
            dfs(i - 1, n);
            
            // 选
            path.push_back(i);
            dfs(i - 1, t - i);
            path.pop_back();
        };
        dfs(9, n);
        return ans;
    }
};

// day30
// 37 解数独
class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char u = board[i][j];
                if (u == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(board, i, j, k)) {
                            u = k;
                            if (solve(board)) return true;
                            u = '.';
                        }   
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
            if (board[i][col] == num) return false;
            if (board[row / 3 * 3 + i / 3][row / 3 * 3 + i % 3] == num) return false;
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};