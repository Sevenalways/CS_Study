##  day25 今日任务4.27

1. 216.组合总和III

2. 17.电话号码的字母组合

   

#### 216.组合总和III

[力扣题目链接](https://leetcode.cn/problems/combination-sum-iii/)

```cpp
class Solution {
    // 输入的角度
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > (i * 2 - d + 1) * d / 2)
                return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= d; j--) {
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
    // 答案的角度
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > (i * 2 - d + 1) * d / 2) return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            //不选i
            if (i > d) dfs(i-1,t);
            // 选i
            path.push_back(i);
            dfs(i-1, t - i);
            path.pop_back();
        };
        dfs(9, n);
        return ans;

    }
};

```

#### 17.电话号码的字母组合

[力扣题目链接](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)



```cpp
class Solution {
    string MAP[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0)
            return {};
        vector<string> ans;
        string path(n, 0);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (auto c : MAP[digits[i] - '0']) {
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};


```



