// 2022.08.02
class MyCircularQueue {
public:
    vector<int> que;
    int front;
    int back;
    int k;
    MyCircularQueue(int k_) {
        k = k_ + 1;
        que.resize(k, 0);
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if((back < front && front - back == 1) || (front < back && back - front + 1 == k)) {
            return false;
        }
        que[back] = value;
        back = (back + 1) % k;
        return true;
    }
    
    bool deQueue() {
        if(front == back) {
            return false;
        }
        front = (front + 1) % k;
        return true;
    }
    
    int Front() {
        if(front == back) {
            return -1;
        }
        return que[front];
    }
    
    int Rear() {
        if(front == back) {
            return -1;
        }
        return que[(back - 1 + k) % k];
    }
    
    bool isEmpty() {
        return front == back;
    }
    
    bool isFull() {
        return (back < front && front - back == 1) || (front < back && back - front + 1 == k);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// 2023.05.17
class MyCircularQueue {
public:
    int k;
    int head;
    int tail;
    int size;
    vector<int> que;
    MyCircularQueue(int k_) {
        k = k_;
        que.resize(k, 0);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        que[head] = value;
        head = (head + 1) % k;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        tail = (tail + 1) % k;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return que[tail];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return que[(head - 1 + k) % k];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */