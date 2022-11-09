// 2022.11.09
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// O(n^2)
class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = new Node(-1);
        dummy->next = head;
        while(head != nullptr) {
            if(head->child == nullptr) {
                head = head->next;
            }
            else {
                Node* temp = head->next;
                Node* chead = flatten(head->child);
                head->next = chead;
                chead->prev = head;
                head->child = nullptr;
                while(head->next != nullptr) {
                    head = head->next;
                }
                head->next = temp;
                if(temp != nullptr) {
                    temp->prev = head;
                }
                head = temp;
            }
        }
        return dummy->next;
    }
};

// O(n)
class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) {
        Node* last = head;
        while(head != nullptr) {
            if(head->child == nullptr) {
                last = head;
                head = head->next;
            }
            else {
                Node* temp = head->next;
                Node* clast = dfs(head->child);
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                if(clast != nullptr) {
                    clast->next = temp;
                }
                if(temp != nullptr) {
                    temp->prev = clast;
                }
                last = head;
                head = clast;
            }
        }
        return last;
    }
};