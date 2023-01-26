// 2022.06.30
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
// plain merge one by one
class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if(a == nullptr || b == nullptr) {
            return a == nullptr ? b : a;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(a != nullptr && b != nullptr) {
            if(a->val < b->val) {
                head->next = a;
                a = a->next;
            }
            else {
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }
        head->next = a == nullptr ? b : a;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(auto list : lists) {
            res = mergeTwo(res, list);
        }
        return res;
    }
};

// merge sort
// Divide and Conquer
class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if(a == nullptr || b == nullptr) {
            return a == nullptr ? b : a;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(a != nullptr && b != nullptr) {
            if(a->val < b->val) {
                head->next = a;
                a = a->next;
            }
            else {
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }
        head->next = a == nullptr ? b : a;
        return dummy->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l == r) {
            return lists[l];
        }
        if(l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        return mergeTwo(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return merge(lists, 0, n - 1);
    }
};

// heap
class Solution {
public:
    struct Cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        for(auto list : lists) {
            if(list != nullptr) {
                heap.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(!heap.empty()) {
            tail->next = heap.top();
            heap.pop();
            tail = tail->next;
            if(tail->next != nullptr) {
                heap.push(tail->next);
            }
        }
        return dummy->next;
    }
};

// 2022.07.12
// heap
class Solution {
public:
    struct cmp{
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pque;
        for(auto list : lists) {
            if(list != nullptr) {
                pque.push(list);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(!pque.empty()) {
            tail->next = pque.top();
            pque.pop();
            tail = tail->next;
            if(tail->next != nullptr) {
                pque.push(tail->next);
            }
        }
        return dummy->next;
    }
};

// recursion, divide and conquer, nice solution
class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if(a == nullptr || b == nullptr) {
            return a == nullptr ? b : a;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(a != nullptr && b != nullptr) {
            if(a->val > b->val) {
                head->next = b;
                head = head->next;
                b = b->next;
            }
            else {
                head->next = a;
                head = head->next;
                a = a->next;
            }
        }
        if(a != nullptr) {
            head->next = a;
        }
        else {
            head->next = b;
        }
        return dummy->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l == r) {
            return lists[l];
        }
        if(l > r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        return mergeTwo(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

// 2022.10.13
class Solution {
public:
    struct Cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pque;
        for(auto& list : lists) {
            if(list != nullptr) {
                pque.push(list);
            }
        }
        while(!pque.empty()) {
            ListNode* cur = pque.top();
            pque.pop();
            temp->next = cur;
            temp = temp->next;
            if(cur->next) {
                pque.push(cur->next);
            }
        }
        return res->next;
    }
};

// 2023.01.26
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
    struct Cmp{
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Cmp> que;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(auto& list : lists) {
            if(list) {
                que.push(list);
            }
        }
        while(!que.empty()) {
            ListNode* cur = que.top();
            que.pop();
            temp->next = cur;
            temp = temp->next;
            if(cur->next) {
                que.push(cur->next);
            }
        }
        return dummy->next;
    }
};