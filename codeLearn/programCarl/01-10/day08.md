##  day08 今日任务4.10

1. 344.反转字符串
2. 541.反转字符串II

3. 卡码网：54.替换数字

4. 151.翻转字符串里的单词

5. 卡码网：55.右旋转字符串


#### 344.反转字符串

[力扣题目链接](https://leetcode.cn/problems/reverse-string/)

```cpp
class Solution {
public:
    void reverseString(vector<char> &s) {
        int  n = s.size();
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);
    }
};
```



#### 541. 反转字符串II

[力扣题目链接](https://leetcode.cn/problems/reverse-string-ii/)

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            if (i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
```



#### 54.替换数字

[卡码网题目链接](https://kamacoder.com/problempage.php?pid=1064)

```cpp
#include <iostream>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        int n0 = s.size();
        int count = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
     
        s.resize(s.size() + count * 5);
        int n1 = s.size();
 
        while (n0) {
            if (s[n0 - 1] >= '0' && s[n0 - 1] <= '9') {
                s[--n1] = 'r';
                s[--n1] = 'e';
                s[--n1] = 'b';
                s[--n1] = 'm';
                s[--n1] = 'u';
                s[--n1] = 'n';
            } else {
                s[--n1] = s[n0 - 1];
            }
            n0--;
        }
        cout << s << endl;       
    }
}

```



####  151.翻转字符串里的单词

[力扣题目链接](https://leetcode.cn/problems/reverse-words-in-a-string/)

```cpp
class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};


```



####  右旋字符串

[卡码网题目链接](https://kamacoder.com/problempage.php?pid=1065)

```cpp

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k = 0;
    string s;
    cin >> k;
    cin >> s;
    int len = s.size();
    
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    
    cout << s << endl;
}
```

