// 2022.04.01
// two queue
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        int out = que1.front();
        que1.pop();
        que1 = que2;
        while(!que2.empty()){
            que2.pop();
        }
        return out;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// 2022.04.01
// one queue
class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size--;
        while(size--){
            que.push(que.front());
            que.pop();
        }
        int out = que.front();
        que.pop();
        return out;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// 2022.04.20
class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size() - 1;
        while(size--) {
            int front = que.front();
            que.pop();
            que.push(front);
        }
        int temp = que.front();
        que.pop();
        return temp;
    }
    
    int top() {
        int size = que.size() - 1;
        while(size--) {
            int front = que.front();
            que.pop();
            que.push(front);
        }
        int temp = que.front();
        que.pop();
        que.push(temp);
        return temp;
        // or just use
        // return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */