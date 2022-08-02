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