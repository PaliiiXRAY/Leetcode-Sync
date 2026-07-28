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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr ){
            fast = fast->next->next;
            slow = slow->next;
             
        }
         ListNode* prev = nullptr;
         ListNode* curr = slow->next;
         while (curr != NULL){
            ListNode* next_ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_;
         }
         while (prev != NULL){
            if(head->val != prev->val) {
                return false;
            }
            else {
                prev = prev->next;
                head = head ->next;
            }
         }
       return true;
    }
};