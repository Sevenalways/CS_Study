##  day29 今日任务5.4

1. 491.非递减子序列

2. 46.全排列

3. 47.全排列II

   

####  491.非递减子序列

[力扣题目链接](https://leetcode.cn/problems/non-decreasing-subsequences/)

```cpp
class Solution {
    bool isRept(vector<int> &nums, int i, int j) {
        if (j > i) 
            for (int k = i; k < j; k++) 
                if (nums[k] == nums[j]) return true;              
        return false;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            if (path.size() > 1) {
                ans.emplace_back(path);
            }
            for (int j = i; j < n; j++) {
                if (path.size() > 0 && nums[j] < path.back())  continue;
                if (isRept(nums, i, j)) continue;
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};


```

#### 46.全排列

[力扣题目链接](https://leetcode.cn/problems/permutations/)

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<bool> on_path(n, false);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!on_path[j]) {
                    path[i] = nums[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};


```

####  47.全排列 II

[力扣题目链接](https://leetcode.cn/problems/permutations-ii/)

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<bool> onPath(n, false);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (j > 0 && nums[j] == nums[j - 1] && !onPath[j - 1])
                    continue;
                if (!onPath[j]) {
                    path[i] = nums[j];
                    onPath[j] = true;
                    dfs(i + 1);
                    onPath[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```



