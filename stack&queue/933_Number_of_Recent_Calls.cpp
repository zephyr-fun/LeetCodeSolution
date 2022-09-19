// 2022.05.06
class RecentCounter {
    queue<int> que;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        que.push(t);
        while(que.front() < t - 3000) {
            que.pop();
        }
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// 2022.09.19
class RecentCounter {
public:
    deque<int> dq;
    RecentCounter() {

    }
    
    int ping(int t) {
        while(!dq.empty() && t - dq.front() > 3000) {
            dq.pop_front();
        }
        dq.push_back(t);
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */