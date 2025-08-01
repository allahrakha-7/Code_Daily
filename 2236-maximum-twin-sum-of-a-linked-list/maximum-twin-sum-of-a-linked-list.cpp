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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {

            slow = slow->next;
            
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {

            ListNode* nextTemp = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            
            curr = nextTemp;
        }

        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
        
            int sum = first->val + second->val;
        
            maxSum = max(maxSum, sum);
        
            first = first->next;
        
            second = second->next;
        }

        return maxSum;
    }
};