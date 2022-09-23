class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int x) : val(x), next(nullptr){}
    };
    MyLinkedList() {
        _dummy = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index > _size - 1 || index < 0){
            return -1;
        }
        else{
            LinkedNode* cur = _dummy->next;
            while(index--){
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = _dummy->next;
        _dummy->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummy;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummy;
        while(index--){
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        LinkedNode* cur = _dummy;
        while(index--){
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// 2022.04.17
// order of public and private
class MyLinkedList {
public:
// define struct 1.init {} 2. struct{}';'
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr){}
    };
    MyLinkedList() {
        _dummy = new ListNode(0);
        _size = 0;
    }
    
    // think about getting 0, with index--, cur should = _dummy->next
    int get(int index) {
        if(index < 0 || index > _size - 1) {
            return -1;
        }
        else {
            ListNode* cur = _dummy->next;
            while(index--) {
                cur = cur->next;
            }
            return cur->val;
        }
        
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = _dummy->next;
        _dummy->next = node;
        _size++;
    }
    // think about getting 0, cur should = _dummy, cur->next != nullptr
    void addAtTail(int val) {
        ListNode* cur = _dummy;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        ListNode* node = new ListNode(val);
        cur->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size || index < 0) {
            return ;
        }
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummy;
        while(index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) {
            return ;
        }
        ListNode* cur = _dummy;
        while(index--) {
            cur = cur->next;
        }
        ListNode* node = cur->next;
        cur->next = cur->next->next;
        delete node;
        _size--;
    }
private:
    int _size;
    ListNode* _dummy;
};

// 2022.09.23
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    MyLinkedList() {
        _dummy = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > _size - 1) {
            return -1;
        }
        ListNode* cur = _dummy->next;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = _dummy->next;
        _dummy->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = _dummy;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new ListNode(val);
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size) {
            return ;
        }
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummy;
        while(index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > _size - 1) {
            return ;
        }
        ListNode* cur = _dummy;
        while(index--) {
            cur = cur->next;
        }
        ListNode* node = cur->next;
        cur->next = cur->next->next;
        delete node;
        _size--;
    }

private:
    int _size;
    ListNode* _dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */