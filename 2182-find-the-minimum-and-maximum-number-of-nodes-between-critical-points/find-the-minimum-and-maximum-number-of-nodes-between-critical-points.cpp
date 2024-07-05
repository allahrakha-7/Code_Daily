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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result(2, -1);
        vector<int> criticalPoints;

        if (!head || !head->next || !head->next->next)
        {
            return result;
        }

        int index = 0;
        ListNode* previous = head;
        ListNode* current = head->next;

        while (current->next)
        {
            if ((current->val > previous->val && current->val > current->next->val) ||
                (current->val < previous->val && current->val < current->next->val))
            {
                criticalPoints.push_back(index);
            }
            previous = current;
            current = current->next;
            index++;
        }
        if (criticalPoints.size() < 2)
        {
            return result;
        }
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++)
        {
            minDistance = min (minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        result[0] = minDistance;
        result[1] = maxDistance;

        return result;
    }
};