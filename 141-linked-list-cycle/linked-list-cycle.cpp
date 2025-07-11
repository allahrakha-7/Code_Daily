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
    bool hasCycle(ListNode *head) {

        if (!head || !head->next) {
            
            return false;
        
        }
        
        // Initialize two pointers
        
        ListNode *slow = head;
        
        ListNode *fast = head; 
        
        // Move pointers until they meet or fast reaches end
        while (fast && fast->next) {
        
            slow = slow->next;  
        
            fast = fast->next->next;
            
            if (slow == fast) {
        
                return true;
        
            }
        }
        return false;
    }
};