##  day11 今日任务4.13

1. 20.有效的括号
2. 1047.删除字符串中的所有相邻重复项
3. 150.逆波兰表达式求值



#### 20.有效的括号

[力扣题目链接](https://leetcode.cn/problems/valid-parentheses/)

```cpp
// 版本一
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x : s) {
            if (st.empty() || x == '(' || x == '{' || x == '[') {
                st.push(x);
            }
            else {
                char ch = st.top();
                if ((ch == '(' && x == ')') || (ch == '{' && x == '}') ||(ch == '[' && x == ']')) {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};

// 版本二
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const char &x : s) {
            if (x == '(') st.push(')');
            else if (x == '{') st.push('}');
            else if (x == '[') st.push(']');
            else if (st.empty() || st.top() != x) return false;
            else st.pop();
        }            
        return st.empty();
    }
};
```



#### 1047.删除字符串中的所有相邻重复项

[力扣题目链接](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for ( char x : s) {
            if (st.empty() || x != st.back()) st.push_back(x);
            else st.pop_back();
        }
        return st;
    }
};
```

#### 150.逆波兰表达式求值

[力扣题目链接](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

```cp
class Solution {
private:
    bool isNumber(string &ch) {
        return !(ch == "+" || ch == "-" || ch == "*" || ch == "/");
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &ch : tokens) {
            if (isNumber(ch)) {
                st.push(stoi(ch));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (ch[0])
                {
                case '+':
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num1 - num2);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                case '/':
                    st.push(num1 / num2);
                    break;
                }
            }
        }
        return st.top();
    }
};
```

