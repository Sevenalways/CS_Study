##  day06 今日任务

1. 242.有效的字母异位词
2. 349.两个数组的交集
3. 202.快乐数
4. 1.两数之和

#### 242.有效的字母异位词

[力扣题目链接](https://leetcode.cn/problems/valid-anagram/)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (char x : s) {
            record[x - 'a']++;
        }
        for (char x : t) {
            record[x - 'a']--;
        }
        for (int x : record) {
            if (x != 0) return false;
        }
        return true;
    }
};
```



#### 349. 两个数组的交集

[力扣题目链接](https://leetcode.cn/problems/intersection-of-two-arrays/)

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (int x : nums2) {
            if (nums.find(x) != nums.end()) {
                ans.insert(x);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
```



#### 202题. 快乐数

[力扣题目链接](https://leetcode.cn/problems/happy-number/)

```cpp
class Solution {
private:
    // 实现该数替换为它每个位置上的数字的平方和
    int getSum (int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
       unorder_set<int> record;
       while (n) {
        int sum = getSum(n);
        if (sum == 1) return true;
        if (record.find(sum) != record.end()) {
            return false;
        } 
        record.insert(sum);
        n = sum;
       }
    }
};
```



#### 1. 两数之和

[力扣题目链接](https://leetcode.cn/problems/two-sum/)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

```

