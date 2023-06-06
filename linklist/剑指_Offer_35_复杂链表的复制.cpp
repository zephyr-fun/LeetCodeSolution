// 2022.08.01
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
        Node* dummy = new Node(-10007);
        Node* t = dummy;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        while(cur != nullptr) {
            Node* temp = new Node(cur->val);
            t->next = temp;
            map[cur] = temp;
            cur = cur->next;
            t = t->next;
        }
        t = dummy->next;
        cur = head;
        while(cur != nullptr) {
            t->random = map[cur->random];
            t = t->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

// 2023.06.06
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-10007);
        Node* t = dummy;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        while(cur != nullptr) {
            Node* temp = new Node(cur->val);
            t->next = temp;
            map[cur] = temp;
            cur = cur->next;
            t = t->next;
        }
        t = dummy->next;
        cur = head;
        while(cur != nullptr) {
            t->random = map[cur->random];
            t = t->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

// optim, don't use hash map