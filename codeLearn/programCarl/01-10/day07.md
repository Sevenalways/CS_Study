##  day07 今日任务

1. 454.四数相加II 
2. 383.赎金信 
3. 15.三数之和 
4. 18.四数之和 

#### 454题.四数相加II

[力扣题目链接](https://leetcode.cn/problems/4sum-ii/)

对于不同数组多个数字相加等于0，一般划分为a + b = - (c + d)，通常使用二分

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record;
        for (int a : nums1) {
            for (int b : nums2) {
                record[a + b]++;
            }
        }
        
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (record.find(- (c + d)) != record.end())
                    ans += record[- (c + d)];
            }
        }
        return ans;
    }
};
```



#### 383. 赎金信

[力扣题目链接](https://leetcode.cn/problems/ransom-note/)

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

    }
};
```

#### 15. 三数之和

[力扣题目链接](https://leetcode.cn/problems/3sum/)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue;
            if (x + nums[i + 1] + nums[i + 2] > 0) break;
            if (x + nums[n - 2] + nums[n - 1] < 0) continue;
            int j = i + 1, k = n - 1;
            while (j < k){
                int s = x + nums[j] + nums[k];
                if (s > 0)  --k;
                else if (s < 0) ++j;
                else {
                    ans.push_back({x, nums[j], nums[k]});
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j);
                    for (--k; k > j && nums[k] == nums[k + 1]; --k);
                } 
            }    
        }
        return ans;
    }
};

```



#### 18. 四数之和

[力扣题目链接](https://leetcode.cn/problems/4sum/)

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int a = 0; a < n - 3; a++) { // 枚举第一个数
            long long x = nums[a]; // 使用 long long 避免溢出
            if (a > 0 && x == nums[a - 1]) continue; // 跳过重复数字
            if (x + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break; // 优化一
            if (x + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
            for (int b = a + 1; b < n - 2; b++) { // 枚举第二个数
                long long y = nums[b];
                if (b > a + 1 && y == nums[b - 1]) continue; // 跳过重复数字
                if (x + y + nums[b + 1] + nums[b + 2] > target) break; // 优化一
                if (x + y + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
                int c = b + 1, d = n - 1;
                while (c < d) { // 双指针枚举第三个数和第四个数
                    long long s = x + y + nums[c] + nums[d]; // 四数之和
                    if (s > target) d--;
                    else if (s < target) c++;
                    else { // s == target
                        ans.push_back({(int) x, (int) y, nums[c], nums[d]});
                        for (c++; c < d && nums[c] == nums[c - 1]; c++); // 跳过重复数字
                        for (d--; d > c && nums[d] == nums[d + 1]; d--); // 跳过重复数字
                    }
                }
            }
        }
        return ans;
    }
};
```

