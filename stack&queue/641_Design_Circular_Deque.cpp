// 2022.08.15
class MyCircularDeque {
public:
    vector<int> nums;
    int k;
    int head;
    int tail;
    int cnt;
    MyCircularDeque(int k_) : k(k_), head(0), tail(0), cnt(0), nums(k_, 0) {

    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        head = (head - 1 + k) % k;
        nums[head] = value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        nums[tail] = value;
        tail = (tail + 1) % k;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        head = (head + 1) % k;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        tail = (tail - 1 + k) % k;
        cnt--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : nums[head];
    }
    
    int getRear() {
        return isEmpty() ? -1 : nums[(tail - 1 + k) % k];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */