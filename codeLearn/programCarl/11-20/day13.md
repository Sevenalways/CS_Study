##  day13 今日任务4.15

1. 239.滑动窗口最大值
2. 前K个高频元素

#### 239. 滑动窗口最大值

[力扣题目链接](https://leetcode.cn/problems/sliding-window-maximum/)

key：队列没有必要维护窗口中的所有值，只需要维护可能成为最大值的即可

借助双端队列，使用单调队列即可：窗口范围[i, j]

1. 队列内只包含窗口内的元素$\Rightarrow$移除nums[i - 1]
2. 队列内元素非严格递减$\Rightarrow$添加nums[j + 1]，需要将队列内<nums[j + 1]的元素删除

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 0)
            return {};
        int n = nums.size();
        deque<int> que;
        vector<int> ans(n - k + 1, 0);
        for (int i = 1 - k, j = 0; j < n; i++, j++) {
            if (i > 0 && nums[i - 1] == que.front()) 
                que.pop_front();
            while (!que.empty() && que.back() < nums[j]) 
                que.pop_back();
            que.push_back(nums[j]);
            if (i >= 0)
                ans[i] = que.front();
        }
        return ans;
    }
};
```



#### 347.前 K 个高频元素

[力扣题目链接](https://leetcode.cn/problems/top-k-frequent-elements/)

题意：首先统计元素出现的次数，利用map实现，然后对次数进行排序，利用容器适配器[优先队列](https://blog.csdn.net/qq_46514118/article/details/120698465)实现

自定义数据类型优先级设置方法：①重载< 运算符，queue定义不变 ②重写仿函数



```cpp
class Solution {
public:
    struct myComparison
        {
        public:
        // 小顶堆
            bool operator() (const pair<int, int> &m, const pair<int, int> &n) {
                return m.second > n.second;
            }
        };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;// map<数值，次数>
        for (int &x : nums) {
            map[x]++;
        }

        //定义优先级队列，创建小顶堆，对元素出现次数排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> q;

        for (auto &[num, count] : map) {
            q.emplace(num, count);
            if (q.size() >k) {
                q.pop();
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};
```

