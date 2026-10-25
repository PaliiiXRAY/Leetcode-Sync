# Rotate List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, rotate the list to the right by `k` places.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

```

 **Example 2:** 

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 500].
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.5 MB (beats 31.27%)  
**Submitted:** 2026-10-07T06:30:10.932Z  

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
           temp = temp->next;
        }
        if (k == len) return head;
        k = k % len;
        if(k == 0) return head;
        temp = head;
        for (int i = 0; i < len - k - 1; i++){
            temp = temp->next;
        }
         ListNode* ans = temp->next;
         temp->next = NULL;
         ListNode* t = ans;
         while (t->next != nullptr){
            t = t->next;
         } t->next = head;
         return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotate-list/)