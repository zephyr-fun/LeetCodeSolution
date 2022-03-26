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