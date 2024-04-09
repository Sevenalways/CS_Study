##  day03 今日任务

1. 203.移除链表元素 
2. 707.设计链表 
3. 206.反转链表

#### 203.移除链表元素

[力扣题目链接](https://leetcode.cn/problems/remove-linked-list-elements/description/)

创建一个dummy结点

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        auto *cur = dummy;
    	while (cur->next) {
            if (cur->next->val == val){
                cur->next = cur->next->next;
            }else {
                cur = cur->next;
			}     
        }
		return dummy->next;
    }
};
```



#### 707.设计链表

[力扣题目链接](https://leetcode.cn/problems/design-linked-list/)



```cpp
class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode *cur = head;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        index = max(0, index);
        size++;
        ListNode *pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode *toAdd = new ListNode(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        ListNode *pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode *p = pred->next;
        pred->next = pred->next->next;
        delete p;
    }
private:
    int size;
    ListNode *head;
};

```



#### 206.翻转链表

[力扣题目链接](https://leetcode.cn/problems/reverse-linked-list/)

// 关键是cur->next = pre;

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head, *nxt = nullptr;
        while(cur) {
            nxt = cur->next ;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
```

