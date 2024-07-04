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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = new ListNode(0);
        ListNode* current = start;
        ListNode* iterator = head->next;
        int sum = 0;

        while (iterator != nullptr)
        {
            if (iterator->val != 0)
            {
                sum += iterator->val;
            } else {
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0;
            }
            iterator = iterator->next;
        }
        return start->next;
    }
};