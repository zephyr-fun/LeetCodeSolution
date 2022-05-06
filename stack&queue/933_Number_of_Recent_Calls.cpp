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