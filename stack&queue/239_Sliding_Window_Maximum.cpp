// 2022.04.01
class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int val){
            if(!que.empty() && que.front() == val){
                que.pop_front();
            }
        }
        void push(int val){
            while(!que.empty() && que.back() < val){
                que.pop_back();
            }
            que.push_back(val);
        }
        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};

// 2022.04.20
class Solution {
private:
    class MyQueue {
    public:
        deque<int> dq;
        void pop(int val) {
            if(!dq.empty() && dq.front() == val) {
                dq.pop_front();
            }
        }
        void push(int val) {
            while(!dq.empty() && dq.back() < val) {
                dq.pop_back();
            }
            dq.push_back(val);
        }
        int front() {
            return dq.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQueue que;
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for(int i = k; i < nums.size(); i++) {
            que.push(nums[i]);
            que.pop(nums[i - k]);
            res.push_back(que.front());
        }
        return res;
    }
};

// 2022.07.11
class MyQueue {
public:
    deque<int> dq;

    void pop(int val) {
        if(!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
    }

    void push(int val) {
        while(!dq.empty() && dq.back() < val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }

    int front() {
        return dq.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        if(nums.size() == 0) {
            return res;
        }
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.emplace_back(que.front());
        for(int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.emplace_back(que.front());
        }
        return res;
    }
};