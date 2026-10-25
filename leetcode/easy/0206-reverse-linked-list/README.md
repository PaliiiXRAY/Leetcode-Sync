# Reverse Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a singly linked list, reverse the list, and return  *the reversed list*.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

```

 **Example 2:** 

```
Input: head = [1,2]
Output: [2,1]

```

 **Example 3:** 

```
Input: head = []
Output: []

```

 

 **Constraints:** 

- The number of nodes in the list is the range [0, 5000].
- -5000 <= Node.val <= 5000

 

 **Follow up:**  A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.6 MB (beats 14.69%)  
**Submitted:** 2026-10-02T22:29:14.394Z  

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr =  head;
        while (curr != nullptr){
          ListNode* next_node = curr -> next;
          //don't get confused by this logic ok basically you 1st create a temp node and we point curr->next to temp
          // then we don't want it anymore to point towards temp i mean we want to reverse right so hum curr->next ko prev pe point kr rhe, because hume prev pe connect krna h reverse krna h
          curr -> next = prev;
          prev = curr;
          // and here you just update the prev pointer to curr
         curr = next_node;
         //same goes with curr point move forward both of them 
         //finally you just cut one pointer node and reverse it to prev pointer remember it yess less gooo
        }
        return prev;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list/)