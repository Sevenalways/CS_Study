##  day30 今日任务5.5

1. 332.重新安排启程

2. 51.N皇后

3. 37.解数独

   

#### 332.重新安排行程

[力扣题目链接](https://leetcode.cn/problems/reconstruct-itinerary/)

```cpp
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        vector<string> ans;
        unordered_map<string, map<string, int>> targets;
        for (auto &tick : tickets) {
            targets[tick[0]][tick[1]]++;
        }
        ans.push_back("JFK");
        function<bool(int)> dfs = [&](int ) {
            if (ans.size() == n + 1) {
                return true;
            }
            for (auto &target : targets[result.back()]) {
                if (target.second > 0) {
                    ans.push_back(target.first);
                    target.second--;
                    if (dfs()) return true;
                    target.second++;
                    ans.pop_back();
                }
            }
            return false;
        };
        dfs()
        return ans;
    }
};


```

#### 51. N皇后

[力扣题目链接](https://leetcode.cn/problems/n-queens/)

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n);
        vector<bool> on_path(n, false), diag1(n * 2 - 1, false), diag2(n * 2 - 1, false);
        // r表示要枚举的行号
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> board(n, string(n, '.'));
                for (int i = 0; i < n; i++) {
                    board[i][col[i]] = 'Q';
                }
                ans.emplace_back(board);
                return;
            }
            // c代表列号
            for (int c = 0; c < n; c++) {
                int sub = r - c + n - 1; //对角线
                if (!on_path[c] && !diag1[r + c] && !diag2[sub]) {
                    col[r] = c;//第r的皇后位于第c列 隐藏了回溯
                    on_path[c] = diag1[r + c] = diag2[sub] = true;
                    dfs(r + 1);
                    on_path[c] = diag1[r + c] = diag2[sub] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};


```

####  37. 解数独

[力扣题目链接](https://leetcode.cn/problems/sudoku-solver/)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // No empty cells left
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false; // Check row
            if (board[row][i] == num) return false; // Check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false; // Check 3x3 box
        }
        return true;
    }
};



```



