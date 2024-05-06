##  day24 今日任务4.26

1. 理论基础

2. 77.组合

   

####  第77题. 组合

[力扣题目链接](https://leetcode.cn/problems/combinations/)

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int i, int k) {
        int d = k - path.size(); // 还要选 d 个数
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


```



