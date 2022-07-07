// 2022.07.07
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = 0;
        unordered_map<int, vector<int>> map;
        for(auto event : events) {
            if(event[1] > maxDay) {
                maxDay = event[1];
            }
            map[event[0]].emplace_back(event[1]);
        }
        priority_queue<int, vector<int>, greater<int>> pque;
        int res = 0;
        for(int i = 1; i <= maxDay; i++) {
            auto cur = map[i];
            for(int i = 0; i < cur.size(); i++) {
                pque.push(cur[i]);
            }
            while(!pque.empty() && pque.top() < i) {
                pque.pop();
            }
            if(!pque.empty()) {
                pque.pop();
                res++;
            }
        }
        return res;
    }
};