##  day27 今日任务4.29

1. 39.组合总和

2. 40.组合总和II

3. 131.分割回文串

   

####  39. 组合总和

[力扣题目链接](https://leetcode.cn/problems/combination-sum/)

```cpp
class Solution {
public:
    //枚举选哪个
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        ranges::sort(candidates);
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                ans.emplace_back(path);
                return;
            }
            if (left < candidates[i])
                return;
            for (int j = i; j < n; j++) {
                path.push_back(candidates[j]);
                dfs(j, left - candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};


class Solution {
public:
    // 选或不选
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                // 找到一个合法组合
                ans.push_back(path);
                return;
            }

            if (i == candidates.size() || left < candidates[i]) {
                return;
            }

            // 不选
            dfs(i + 1, left);

            // 选
            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back(); // 恢复现场
        };

        dfs(0, target);
        return ans;
    }
};

```

####  40.组合总和II

[力扣题目链接](https://leetcode.cn/problems/combination-sum-ii/)

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (left < candidates[i])
                    return;
                if (j > i && candidates[j] == candidates[j - 1])
                    continue;
                path.emplace_back(candidates[j]);
                dfs(j + 1, left - candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```

####  131.分割回文串

[力扣题目链接](https://leetcode.cn/problems/palindrome-partitioning/)

```cpp
class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
// 答案视角：枚举子串结束位置
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

```cpp
// 输入的视角：逗号选或不选
//假设每对相邻字符之间有个逗号，那么就看每个逗号是选还是不选。
//也可以理解成：是否要把 s[i]s[i]s[i] 当成分割出的子串的最后一个字符。
class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();
        // start 表示当前回字子串的开始位置，i表示选到第几个字母了
        function<void(int, int)> dfs = [&](int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            // 不选 i 和 i+1 之间的逗号
            if (i < n - 1)
                dfs(i + 1, start);

            // 选 i 和 i+1 之间的逗号
            if (isPalindrome(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

```

