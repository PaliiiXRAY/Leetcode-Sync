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