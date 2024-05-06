##  day28 今日任务4.30

1. 93.复原IP地址

2. 78.子集

3. 90.子集II

   

#### 93.复原IP地址

[力扣题目链接](https://leetcode.cn/problems/restore-ip-addresses/)

```cpp
class Solution {
private:
    bool isValid(string& s, int left, int right) {
        if (right > left && s[left] == '0')
            return false; // leading zeros are not allowed
        return stoi(s.substr(left, right - left + 1)) <= 255;
    }

public:
    vector<string> restoreIpAddresses(string& s) {
        int n = s.length();
        if (n < 4 || n > 12)
            return {};
        vector<string> ans;
        string path;
	// i表示字符串位置，index表示区间
        function<void(int, int)> dfs = [&](int i, int index) {
            if (i == n && index == 4) {
                ans.emplace_back(path);
                return;
            }
            if (index >= 4)
                return; // no valid IP address possible

            for (int len = 1; len <= 3 && i + len <= n; len++) {
                if (isValid(s, i, i + len - 1)) {
                    string part = s.substr(i, len);
                    if (index < 3)
                        part += ".";
                    path += part;
                    dfs(i + len, index + 1);
                    path.erase(path.size() - part.size()); //
                }
            }
        };

        dfs(0, 0);
        return ans;
    }
};
```

####  78.子集

[力扣题目链接](https://leetcode.cn/problems/subsets/)

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //方法2 答案的视角，选哪个数
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back(); // 恢复现场
            }    
        };
        dfs(0);
        return ans;
    }
};


```

####  90.子集II

[力扣题目链接](https://leetcode.cn/problems/subsets-ii/)

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        ranges::sort(nums);
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) {
                if (j > i && nums[j] == nums[j - 1])
                    continue;
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



