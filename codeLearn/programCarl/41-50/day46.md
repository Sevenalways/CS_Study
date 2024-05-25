## day46 今日任务5.21

1. 139.单词拆分
2. 多重背包

#### 139.单词拆分

[力扣题目链接](https://leetcode.cn/problems/word-break/)

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // 本题为排列 先背包 再物品：因为要求物品有序
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 0; j < i; j++) { // 遍历物品
                string word = s.substr(j, i - j);//(起始位置, 个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                    break; // 剪枝优化1 如果dp[i]已经为true，就没必要继续了
                }
            }
        }
        return dp[n];
    }
};
```

```cpp
// 剪枝优化2 限制子串长度
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        
        // 计算字典中最长单词的长度
        int maxWordLength = 0;
        for (const string& word : wordDict) {
            maxWordLength = max(maxWordLength, (int)word.size());
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = i - 1; j >= max(0, i - maxWordLength); j--) { // 遍历物品
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                    break; // 如果 dp[i] 已经为 true，就没必要继续了
                }
            }
        }
        return dp[n];
    }
};

```

#### 多重背包

有N种物品和一个容量为V 的背包。第i种物品最多有Mi件可用，每件耗费的空间是Ci ，价值是Wi 。求解将哪些物品装入背包可使这些物品的耗费的空间 总和不超过背包容量，且价值总和最大。

多重背包和01背包是非常像的， 为什么和01背包像呢？

每件物品最多有Mi件可用，把Mi件摊开，其实就是一个01背包问题了。