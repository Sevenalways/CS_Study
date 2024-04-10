##  day04 今日任务

1. 24.两两交换链表中的节点  
2. 19.删除链表的倒数第N个节点 
3. 面试题 02.07. 链表相交  
4. 142.环形链表II
   



####  24. 两两交换链表中的节点 

[力扣题目链接](https://leetcode.cn/problems/swap-nodes-in-pairs/)

// 可参考25.[K个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/description/)

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;
            
            cur = cur->next->next;
        }
        return dummy->next;
    }
};
```



####  19.删除链表的倒数第N个节点 

[力扣题目链接](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

// 快慢指针，快指针先走N步，接下来快慢指针一起走，当快指针结束时，慢指针到达倒数第N个节点

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = dummy;
        if (head == nullptr) return head;
        for (int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
            slow -> next = slow -> next -> next;
        return dummy -> next;
    }
    
};
```

#### 160. 链表相交

[力扣题目链接](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

// 将两个链表加起来，若相交，则最后相同段为交点

// eg:链表A+链表B=链表C1

链表B+链表A=链表C2

A -> `a1 a2 c1 c2 c3`

B -> `b1 b2 b3 c1 c2 c3`

C1 -> `a1 a2 c1 c2 c3 b1 b2 b3 c1 c2 c3`

C2 -> `b1 b2 b3 c1 c2 c3 a1 a2 c1 c2 c3`

此时C1和C2的长度一定相同。 而C1和C2的结尾就一定是相交的链表。

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p1 = headA, *p2 = headB;
        while (ture) {
            if (p1 == p2) return p1;
            if (p1) p1 = p1->next;
            else p1 = headB;
            if (p2) p2 = p2->next;
            else p2 = headA;
        }
    }
};
```



####  142.环形链表II 

[力扣题目链接](https://leetcode.cn/problems/linked-list-cycle-ii/)

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head, *pos = head;;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (pos != slow) {
                    slow = slow->next;
                    pos = pos->next;
                }
                return pos;
            }
        }
        return nullptr;
    }
};
```

