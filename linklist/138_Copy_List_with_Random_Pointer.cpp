// 2022.09.24
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
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        Node* dummy = new Node(0);
        Node* pre = dummy;
        Node* node;
        while(cur != nullptr) {
            node = new Node(cur->val);
            pre->next = node;
            pre = pre->next;
            map[cur] = node;
            cur = cur->next;
        }
        cur = head;
        node = dummy->next;
        while(cur != nullptr) {
            if(map.count(cur->random)) {
                node->random = map[cur->random];
            }
            cur = cur->next;
            node = node->next;
        }
        return dummy->next;
    }
};