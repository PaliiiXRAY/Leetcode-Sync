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