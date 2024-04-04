## day02 今日任务

### 977.有序数组的平方 ，209.长度最小的子数组 ，59.螺旋矩阵II ，

#### 977.有序数组的平方

[力扣题目链接](https://leetcode.cn/problems/squares-of-a-sorted-array/)

key：有序数组平方后，最大值一定出现在两端，中间为最小值

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, k = n - 1;
        while (left <= right){
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                ans[k--] = nums[left] * nums[left];
                left++;
            } else {
                ans[k--] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};
```



#### 209.长度最小的子数组

[力扣题目链接](https://leetcode.cn/problems/minimum-size-subarray-sum/)

滑动窗口

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, ans = n + 1, sum = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            
        }
        return ans == n + 1 ? 0 : ans;
    }
};
```







#### 59.螺旋矩阵II

[力扣题目链接](https://leetcode.cn/problems/spiral-matrix-ii/)

1. 初始化一个n*n大小的矩阵，然后模拟整个填入过程，注意循环不变量。
2. 定义当前上右下左边界t,r,b,l ， 初始值num = 1， 迭代终点target = n * n；
3. 当num <= tar 时，始终按照从左到右，从上到下，从右到左，从下到上的过程循环填入，循环一次后，各边界向内收缩1
4. 使用num <= tar 是为了解决当n为奇数，矩阵中心需要单独定义此次的问题。

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int> (n, 0));
        int num = 1, tar = n * n;
        int t = 0, r = n - 1, b = n - 1, l = 0;
        while (num <= tar) {
            for (int i = l; i <= r; i++)  ans[t][i] = num++;
            t++;
            for (int i = t; i <= b; i++) ans[i][r] = num++;
            r--;
            for (int i = r; i >= l; i--) ans[b][i] = num++;
            b--;
            for (int i = b; i >= t; i--) ans[i][l] = num++;
            l++;
        }
        return ans;
    }
};
```

