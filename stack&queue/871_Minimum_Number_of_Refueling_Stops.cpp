// 2022.07.02
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pque;
        int n = stations.size();
        int idx = 0;
        int remain = startFuel;
        int loc = 0;
        int res = 0;
        while(loc < target) {
            if(remain == 0) {
                if(!pque.empty() && ++res >= 0) {
                    remain += pque.top();
                    pque.pop();
                }
                else {
                    return -1;
                }
            }
            loc += remain;
            remain = 0;
            while(idx < n && stations[idx][0] <= loc) {
                pque.push(stations[idx][1]);
                idx++;
            }
        }
        return res;
    }
};

// repeat
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int remain = startFuel;
        int loc = 0;
        int n = stations.size();
        int res = 0;
        int idx = 0;
        priority_queue<int> pque;
        while(loc < target) {
            if(remain == 0) {
                if(!pque.empty()) {
                    remain += pque.top();
                    pque.pop();
                }
                else {
                    return -1;
                }
                res++;
            }
            loc += remain;
            remain = 0;
            while(idx < n && stations[idx][0] <= loc) {
                pque.push(stations[idx][1]);
                idx++;
            }
        }
        return res;
    }
};

// 2022.09.24
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        int cur = 0;
        int rest = startFuel;
        int idx = 0;
        int n = stations.size();
        priority_queue<int> pq;
        while(cur < target) {
            // rest--;
            // cur++;
            if(rest == 0) {
                if(pq.empty()) {
                    return -1;
                }
                rest += pq.top();
                pq.pop();
                res++;
            }
            cur += rest;
            rest = 0;
            while(idx < n && cur >= stations[idx][0]) {
                pq.push(stations[idx][1]);
                idx++;
            }
        }
        return res;
    }
};

// 2023.02.14
// use stack as a backup
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int, vector<int>, less<int>> pque;
        int loc = 0;
        int remain = startFuel;
        int n = stations.size();
        int idx = 0;
        int res = 0;
        while(loc < target) {
            if(remain == 0) {
                if(!pque.empty()) {
                    remain = pque.top();
                    pque.pop();
                    res++;
                }
                else {
                    return -1;
                }
            }
            loc += remain;
            remain = 0;
            while(idx < n && loc >= stations[idx][0]) {
                pque.push(stations[idx][1]);
                idx++;
            }
        }
        return loc < target ? -1 : res;
    }
};