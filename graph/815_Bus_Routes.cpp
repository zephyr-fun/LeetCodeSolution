// 2022.07.18
class Solution {
public:
    vector<vector<int>> routes;
    int source;
    int target;
    unordered_map<int, vector<int>> map;
    int n;
    int update(queue<pair<int, int>>& que, unordered_map<int, int>& cur, unordered_map<int, int>& other) {
        int size = que.size();
        for(int i = 0; i < size; i++) {
            auto [bus, stop] = que.front();
            que.pop();
            int step = cur[bus];
            if(other.count(bus)) {
                return step + other[bus] - 1;
            }
            for(int i = 0; i < routes[bus].size(); i++) {
                if(routes[bus][i] == stop) {
                    continue;
                }
                if(routes[bus][i] == target) {
                    return step;
                }
                auto buses = map[routes[bus][i]];
                for(int j = 0; j < buses.size(); j++) {
                    if(buses[j] == bus) {
                        continue;
                    }
                    if(cur.count(buses[j])) {
                        continue;
                    }
                    que.push({buses[j], i});
                    cur[buses[j]] = step + 1;
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes_, int source_, int target_) {
        source = source_;
        target = target_;
        routes = routes_;
        if(source == target) {
            return 0;
        }
        n = routes.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                map[routes[i][j]].emplace_back(i);
            }
        }
        queue<pair<int, int>> sque; // bus, stop
        queue<pair<int, int>> tque;
        unordered_map<int, int> smap; // bus, step
        unordered_map<int, int> tmap;
        for(int i = 0; i < map[source].size(); i++) {
            sque.push({map[source][i], source});
            smap[map[source][i]] = 1;
        }
        for(int i = 0; i < map[target].size(); i++) {
            tque.push({map[target][i], target});
            tmap[map[target][i]] = 1;
        }
        int t = -1;
        while(!sque.empty() && !tque.empty()) {
            if(sque.size() <= tque.size()) {
                t = update(sque, smap, tmap);
            }
            else {
                t = update(tque, tmap, smap);
            }
            if(t != -1) {
                return t;
            }
        }
        return -1;
    }
};

// 2022.11.15
class Solution {
public:
    vector<vector<int>> routes;
    int source;
    int target;
    unordered_map<int, vector<int>> map;
    int n;
    int update(queue<pair<int, int>>& que, unordered_map<int, int>& cur, unordered_map<int, int>& other) {
        int size = que.size();
        for(int i = 0; i < size; i++) {
            auto [bus, stop] = que.front();
            que.pop();
            int step = cur[bus];
            if(other.count(bus)) {
                return step + other[bus] - 1;
            }
            for(int i = 0; i < routes[bus].size(); i++) {
                if(routes[bus][i] == stop) {
                    continue;
                }
                if(routes[bus][i] == target) {
                    return step;
                }
                auto buses = map[routes[bus][i]];
                for(int j = 0; j < buses.size(); j++) {
                    if(buses[j] == bus) {
                        continue;
                    }
                    if(cur.count(buses[j])) {
                        continue;
                    }
                    que.push({buses[j], routes[bus][i]});
                    cur[buses[j]] = step + 1;
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes_, int source_, int target_) {
        source = source_;
        target = target_;
        routes = routes_;
        if(source == target) {
            return 0;
        }
        n = routes.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                map[routes[i][j]].emplace_back(i);
            }
        }
        queue<pair<int, int>> sque; // bus, stop
        queue<pair<int, int>> tque;
        unordered_map<int, int> smap; // bus, step
        unordered_map<int, int> tmap;
        for(int i = 0; i < map[source].size(); i++) {
            sque.push({map[source][i], source});
            smap[map[source][i]] = 1;
        }
        for(int i = 0; i < map[target].size(); i++) {
            tque.push({map[target][i], target});
            tmap[map[target][i]] = 1;
        }
        int t = -1;
        while(!sque.empty() && !tque.empty()) {
            if(sque.size() <= tque.size()) {
                t = update(sque, smap, tmap);
            }
            else {
                t = update(tque, tmap, smap);
            }
            if(t != -1) {
                return t;
            }
        }
        return -1;
    }
};