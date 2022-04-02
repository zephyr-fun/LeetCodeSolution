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