// 2022.07.11
class MyQueue {
public:
    deque<int> dq;

    void push(int val) {
        while(!dq.empty() && dq.back() < val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }

    void pop(int val) {
        if(!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
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
            que.pop(nums[i - k]); // note subscript
            que.push(nums[i]);
            res.emplace_back(que.front());
        }
        return res;
    }
};

// 2022.08.29
class MyQueue {
public:
    void pop(int num) {
        if(!dq.empty() && dq.front() == num) {
            dq.pop_front();
        }
    }

    void push(int num) {
        while(!dq.empty() && dq.back() < num) {
            dq.pop_back();
        }
        dq.push_back(num);
    }

    int front() {
        return dq.front();
    }

private:
    deque<int> dq;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        MyQueue que;
        vector<int> res;
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.emplace_back(que.front());
        for(int i = k; i < n; i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.emplace_back(que.front());
        }
        return res;
    }
};