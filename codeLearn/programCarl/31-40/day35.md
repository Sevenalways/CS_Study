## day35 今日任务5.10

1.  435.无重叠区域
2.  763.划分字母区间
3.  56.合并区间

####  435. 无重叠区间

[力扣题目链接](https://leetcode.cn/problems/non-overlapping-intervals/)

左右排序均可，其中一个记录的是重复了的区间，一个记录的是保留区间

```cpp
class Solution {
public:
    // 找出其中与前一个区间不重合且右端点最小的区间即可
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;
        ranges::sort(intervals, cmp);
        int count = 1;// 统计选择了的区间
        int right = intervals[0][1];
        // 遍历，并维护上一个选择区间的右端点
        for (auto& inter : intervals) {
            if(inter[0] >= right) {
                count++;
                right = inter[1];
            }

        }
        return n - count;
    }
};

```

```CPP
class Solution {
public:
    // 左边界排序，统计重复的区间
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;
        ranges::sort(intervals, cmp);
        int count = 0;// 统计重复的区间
        int right = intervals[0][1];
        for (auto& inter : intervals) {
            if(inter[0] >= right) right = inter[1];
            else { // 区间重叠
                count++;
                right = min(right, inter[1]);
            }
        }
        return count - 1;// 第一段不属于重复区间
    }
};
```

####  763.划分字母区间

[力扣题目链接](https://leetcode.cn/problems/partition-labels/)

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> map(26,0);
        // 统计每个字母最后出现的位置
        for (int i = 0; i < n; i++) {
            map[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int i = 0;
        while(i < n) {
            int pos = map[s[i] - 'a'];
            for(int j = i; j < pos; j++) {
                if (map[s[j] - 'a'] <= pos) continue;
                else pos = map[s[j] - 'a'];
            }
            ans.push_back(pos - i + 1);
            i = pos + 1;
        }
        return ans;
    }
};
```

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
```





#### 56. 合并区间

[力扣题目链接](https://leetcode.cn/problems/merge-intervals/)

```cpp
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        ranges::sort(intervals, cmp);
        vector<vector<int>> ans;
        vector<int> path = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > path[1]) {
                ans.emplace_back(path);
                path = intervals[i];
            } else {
                path[1] = max(intervals[i][1], path[1]); 
            }
        }
        ans.emplace_back(path);
        return ans;
    }
};
```

