// 2022.09.05
// struct version
class Solution {
    struct node {
        int finish;
        int id;

        bool operator > (const node& other) const {
            if(finish == other.finish) {
                return id > other.id;
            }
            return finish > other.finish;
        }
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k);
        priority_queue<node, vector<node>, greater<>> working;
        set<int> waiting;
        vector<int> ans;
        int m = 0;
        for(int i = 0; i < k; i++) {
            waiting.insert(i);
        }
        for(int i = 0; i < arrival.size(); i++) {
            while(working.size() && working.top().finish <= arrival[i]) {
                waiting.insert(working.top().id);
                working.pop();
            }
            auto cur = waiting.lower_bound(i % k);
            if(cur == waiting.end()) {
                cur = waiting.begin();
            }
            if(cur == waiting.end()) {
                continue;
            }
            working.push({arrival[i] + load[i], *cur});
            m = max(m, ++cnt[*cur]);
            waiting.erase(cur);
        }
        for(int i = 0; i < k; i++){
            if(cnt[i] == m) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// pair version
using PII = pair<int, int>;  // 结束时间，机器id
int cnts[100010];

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        memset(cnts, 0, sizeof(cnts));
        int n = arrival.size();  // load.size==n
        int max_cnt = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q;  // c++默认大顶
        set<int> free;
        
        // 起始，全部空闲
        for(int i = 0; i < k; i++) {
            free.insert(i);
        }
        for(int i = 0; i < n; i++) {
            int start = arrival[i];
            int end = start + load[i];
            while(!q.empty() && q.top().first <= start) {
                PII front = q.top();
                q.pop();
                free.insert(front.second);
            }
            set<int>::const_iterator dst;
            dst = free.lower_bound(i % k);
            if(dst == free.end()) {
                dst = free.lower_bound(0);
            }
            if(dst == free.end()) {
                continue;
            }
            int work_idx = *dst;
            free.erase(dst);
            q.push({end, work_idx});
            max_cnt = max(max_cnt, ++cnts[work_idx]);
        }
        vector<int> res;
        for(int i = 0; i < k; ++i) {
            if (cnts[i] == max_cnt) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// 2023.05.09
class Solution {
public:
    struct Node {
        int id;
        int endTime;
        bool operator > (const Node& other) const{
            if(endTime == other.endTime) {
                return id > other.id;
            }
            return endTime > other.endTime;
        }
    };
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k);
        priority_queue<Node, vector<Node>, greater<>> working;
        set<int> waiting;
        vector<int> res;
        int m = 0;
        for(int i = 0; i < k; i++) {
            waiting.insert(i);
        }
        for(int i = 0; i < arrival.size(); i++) {
            while(!working.empty() && working.top().endTime <= arrival[i]) {
                waiting.insert(working.top().id);
                working.pop();
            }
            auto cur = waiting.lower_bound(i % k);
            if(cur == waiting.end()) {
                cur = waiting.begin();
            }
            if(cur == waiting.end()) {
                continue;
            }
            working.push({*cur, arrival[i] + load[i]});
            m = max(m, ++cnt[*cur]);
            waiting.erase(cur);
        }
        for(int i = 0; i < k; i++) {
            if(cnt[i] == m) {
                res.push_back(i);
            }
        }
        return res;
    }
};