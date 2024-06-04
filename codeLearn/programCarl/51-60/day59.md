## day59 今日任务6.3

1. 503.下一个更大的元素II
2. 42.接雨水



#### 503.下一个更大元素II

[力扣题目链接](https://leetcode.cn/problems/next-greater-element-ii/)



```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        if (nums.size() == 0) return result;
        stack<int> st;
        for (int i = 0; i < nums.size() * 2; i++) {
            // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};
```



#### 42. 接雨水

[力扣题目链接](https://leetcode.cn/problems/trapping-rain-water/)

```cpp
class Solution {
public:
    // 双指针
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int pre_max =0, suf_max = 0;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max > suf_max) {
                ans += suf_max - height[right];
                right--;
            } else {
                ans += pre_max - height[left];
                left++;
            }
        }
        return ans;
    }
};
```

```cpp
class Solution {
public:
    // 单调栈
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h; // 面积的高
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
```

