// 2022.04.01
class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;
    MyQueue() {
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        int out;
        if(!outStack.empty()){
            out = outStack.top();
            outStack.pop();
            return out;
        }
        else{
            while(!inStack.empty()){
                int temp = inStack.top();
                inStack.pop();
                outStack.push(temp);
            }
            out = outStack.top();
            outStack.pop();
            return out;
        }
    }
    
    int peek() {
        if(!outStack.empty()){
            return outStack.top();
        }
        else{
            while(!inStack.empty()){
                int temp = inStack.top();
                inStack.pop();
                outStack.push(temp);
            }
            return outStack.top();
        }
    }
    
    bool empty() {
        // if(inStack.empty() && outStack.empty()){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// 2022.04.20
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()) {
            int temp = st2.top();
            st2.pop();
            return temp;
        }
        else {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int temp = st2.top();
            st2.pop();
            return temp;
        }
    }
    
    int peek() {
        if(!st2.empty()) {
            return st2.top();
        }
        else {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */