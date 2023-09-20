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

// 2022.08.29
// e.g. [1, 3, 0, -1, -3, -5]
// queue
// [1], [3], [3, 0], [3, 0, -1], [0, -1, -3], [-1, -3, -5]
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

// 2022.09.22
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dque;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            while(!dque.empty() && dque.back() < nums[i]) {
                dque.pop_back();
            }
            dque.push_back(nums[i]);
        }
        vector<int> res;
        res.emplace_back(dque.front());
        for(int i = k; i < n; i++) {
            if(!dque.empty() && nums[i - k] == dque.front()) {
                dque.pop_front();
            }
            while(!dque.empty() && dque.back() < nums[i]) {
                dque.pop_back();
            }
            dque.push_back(nums[i]);
            res.emplace_back(dque.front());
        }
        return res;
    }
};

// 2023.05.20
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.emplace_back(dq.front());
        for(int i = k; i < n; i++) {
            if(!dq.empty() && dq.front() == nums[i - k]) {
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.emplace_back(dq.front());
        }
        return res;
    }
};

// 2023.09.20
// 单调队列，内部递减，保证最大值在队头，用deque分别实现单调队列的push和pop
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.emplace_back(dq.front());
        for (int i = k; i < n; i++) {
            if (!dq.empty() && dq.front() == nums[i - k]) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.emplace_back(dq.front());
        }
        return res;
    }
};