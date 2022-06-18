// 2022.06.18
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
        Node* cur = head;
        int maxVal = -0x3f3f3f3f;
        int minVal = 0x3f3f3f3f;
        Node* maxNode = nullptr;
        if(cur == nullptr) {
            cur = new Node(insertVal);
            cur->next = cur;
            head = cur;
        }
        else if(cur == cur->next) {
            Node* insert = new Node(insertVal);
            cur->next = insert;
            insert->next = cur;
        }
        else {
            minVal = cur->val;
            maxVal = cur->val;
            maxNode = cur;
            while(cur->next != head) {
                cur = cur->next;
                minVal = min(minVal, cur->val);
                maxVal = max(maxVal, cur->val);
                maxNode = maxVal == cur->val ? cur : maxNode;
            }
            if(insertVal <= minVal || insertVal >= maxVal) {
                Node* insert = new Node(insertVal);
                Node* temp = maxNode->next;
                maxNode->next = insert;
                insert->next = temp;
            }
            else {
                while(!(cur->val <= insertVal && cur->next->val >= insertVal)) {
                    cur = cur->next;
                }
                Node* insert = new Node(insertVal);
                Node* temp = cur->next;
                cur->next = insert;
                insert->next = temp;
            }
        }
        return head;
    }
};

// clear your mind
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* insert = new Node(insertVal);
        insert->next = insert;
        if(head == nullptr) {
            return insert;
        }
        Node* cur = head;
        int maxVal = cur->val;
        int minVal = cur->val;
        Node* maxNode = cur;
        while(cur->next != head) {
            cur = cur->next;
            minVal = min(minVal, cur->val);
            maxVal = max(maxVal, cur->val);
            maxNode = maxVal == cur->val ? cur : maxNode;
        }
        if(minVal == maxVal) {
            insert->next = head->next;
            head->next = insert;
        }
        else {
            if(insertVal <= minVal || insertVal >= maxVal) {
                insert->next = maxNode->next;
                maxNode->next = insert;
            }
            else {
                while(!(cur->val <= insertVal && cur->next->val >= insertVal)) {
                    cur = cur->next;
                }
                insert->next = cur->next;
                cur->next = insert;
            }
        }
        return head;
    }
};