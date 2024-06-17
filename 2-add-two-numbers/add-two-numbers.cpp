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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* current = head;
        int carry = 0;

        while (a != nullptr || b != nullptr)
        {
            int x = (a != nullptr) ? a->val : 0;
            int y = (b != nullptr) ? b->val : 0;
            int sum = carry + x + y;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (a != nullptr) a = a->next;
            if (b != nullptr) b = b->next;
        }

        if (carry > 0) 
        {
            current->next = new ListNode(carry);
        }

        ListNode* result = head->next;
        delete head;
        return result;
    }
};