// 2022.08.02
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            Node* res = new Node(insertVal);
            res->next = res;
            return res;
        }
        Node* temp = new Node(insertVal);
        Node* cur = head->next;
        int maxVal = head->val;
        int minVal = head->val;
        Node* max = head;
        Node* min = head;
        Node* start = nullptr;
        Node* end = nullptr;
        while(cur != head) {
            if(cur->val > maxVal) {
                maxVal = cur->val;
                max = cur;
            }
            if(cur->val < minVal) {
                minVal = cur->val;
                min = cur;
            }
            cur = cur->next;
        }
        if(maxVal == minVal) {
            Node* next = max->next;
            max->next = temp;
            temp->next = next;
            return head;
        }
        cur = head->next;
        while(!(cur->val == maxVal && cur->next->val == minVal)) {
            cur = cur->next;
        }
        end = cur;
        start = cur->next;
        if(insertVal >= maxVal || insertVal <= minVal) {
            end->next = temp;
            temp->next = start;
        }
        else {
            while(!(cur->val <= insertVal && cur->next->val >= insertVal)) {
                cur = cur->next;
            }
            Node* next = cur->next;
            cur->next = temp;
            temp->next = next;
        }
        return head;
    }
};

// 2022.08.19
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node * t = new Node(insertVal);
        t->next = t;
        if(head == nullptr) {
            return t;
        }
        Node* res = head;
        int minVal = head->val;
        int maxVal = head->val;
        while(head->next != res) {
            head = head->next;
            minVal = min(minVal, head->val);
            maxVal = max(maxVal, head->val);
        }
        if(minVal == maxVal) {
            t->next = res->next;
            res->next = t;
        }
        else {
            while(!(head->val == maxVal && head->next->val == minVal)) {
                head = head->next;
            }
            while(!(insertVal <= minVal || insertVal >= maxVal) && !(head->val <= insertVal && insertVal <= head->next->val)) {
                head = head->next;
            }
            t->next = head->next;
            head->next = t;
        }
        return res;
    }
};