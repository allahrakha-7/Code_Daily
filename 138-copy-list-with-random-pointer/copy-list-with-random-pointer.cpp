/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> nodeMap;
        
        Node* curr = head;

        while (curr) {
        
            nodeMap[curr] = new Node(curr->val);
            
            curr = curr->next;
        }
        
        curr = head;

        while (curr) {
        
            Node* copiedNode = nodeMap[curr];
            
            if (curr->next) {

                copiedNode->next = nodeMap[curr->next];
            }
            
            if (curr->random) {

                copiedNode->random = nodeMap[curr->random];
            }
            
            curr = curr->next;
        }
        
        return nodeMap[head];
    }
};