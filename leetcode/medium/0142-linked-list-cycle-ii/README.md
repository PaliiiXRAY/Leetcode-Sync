# Linked List Cycle II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, return  *the node where the cycle begins. If there is no cycle, return* `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to (**0-indexed**). It is `-1` if there is no cycle.  **Note that**  `pos`  **is not passed as a parameter**.

 **Do not modify**  the linked list.

 

 **Example 1:** 

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

```

 **Example 2:** 

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

```

 **Example 3:** 

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

```

 

 **Constraints:** 

- The number of the nodes in the list is in the range [0, 104].
- -105 <= Node.val <= 105
- pos is -1 or a valid index in the linked-list.

 

 **Follow up:**  Can you solve it using `O(1)` (i.e. constant) memory?

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 98.01%)  
**Memory:** 11.4 MB (beats 21.23%)  
**Submitted:** 2026-10-02T23:18:10.136Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Phase 1: Do they collide?
        bool hasCycle = false;
        
        // YOUR LOGIC HERE: 
        // Move fast by 2, slow by 1. 
        while (fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        // If they ever equal each other, set hasCycle = true and break the loop.
            if(fast == slow){
            hasCycle = true;
            break;
        }
        }
        
        // If fast reached the end of the list, there's no cycle
        if (!hasCycle) return nullptr;
        
        // Phase 2: Find the exact start node
        // 1. Reset slow to the head
        slow = head;
        
        // YOUR LOGIC HERE:
        // 2. While slow != fast, move BOTH by exactly 1 step.
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // They collided again! Return the node.
        return slow;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/linked-list-cycle-ii/)