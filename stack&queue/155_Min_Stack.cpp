// 2022.09.13
// multiset
class MinStack {
public:
    stack<int> st;
    multiset<int> set;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        set.insert(val);
    }
    
    void pop() {
        auto it = set.find(st.top());
        set.erase(it);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *set.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// assistant stack, much more faster
class MinStack {
public:
    stack<int> st;
    stack<int> as_st;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(as_st.empty() || val <= as_st.top()) {
            as_st.push(val);
        }
    }
    
    void pop() {
        if(st.top() == as_st.top()) {
            as_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return as_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */