day34 今日任务5.9

1.  860.柠檬水找零
2.  406.根据身高重建队列
3.  452.用最少数量的箭引爆气球

#### 860.柠檬水找零

[力扣题目链接](https://leetcode.cn/problems/lemonade-change/)

尽量先用10块的余额

```CPP
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            else if (bill == 10) {
                five--;
                ten++;
            } else {
                if (ten) ten--, five--;
                else five -= 3;
            }
            if (five < 0) return false;
        }
        return true;
    }
};
```

####  406.根据身高重建队列

[力扣题目链接](https://leetcode.cn/problems/queue-reconstruction-by-height/)

```cpp
// 版本一
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (auto& peo : people) {
            int pos = peo[1];
            que.insert(que.begin() + pos, peo);
        }
        return que;
    }
};
```

```CPP
// 版本二
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        ranges::sort(people, cmp);
        list<vector<int>> que;// 借助链表实现，避免vector插入
        for (auto& peo : people) {
            int pos = peo[1];
            auto it = que.begin();
            while (pos--) {
                it++;
            }
            que.insert(it, peo);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
```

####  452. 用最少数量的箭引爆气球

[力扣题目链接](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

```cpp
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    // 记录当前区间的最小右边界
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0)
            return 0;
        int ans = 1;
        ranges::sort(points, cmp); // 按照气球的起始位置升序
        int right = points[0][1];
        for (const vector<int>& point : points) {
            if (point[0] > right) {
                right = point[1];
                ans++;
            } else {
                right = min(point[1], right);
            }
        }
        return ans;
    }
};
```

