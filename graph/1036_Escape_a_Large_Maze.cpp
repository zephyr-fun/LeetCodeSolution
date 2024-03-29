// 2022.07.03
class Solution {
public:
    vector<vector<int>> blocked;
    vector<int> source;
    vector<int> target;
    int maxPoint;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<long long> set;

    bool isEscapePossible(vector<vector<int>>& blocked_, vector<int>& source_, vector<int>& target_) {
        blocked = blocked_;
        source = source_;
        target = target_;
        maxPoint = (blocked.size() + 1) * (blocked.size() + 2) / 2;
        for(int i = 0; i < blocked.size(); i++) {
            set.insert(blocked[i][0] * 1e6 + blocked[i][1]);
        }
        return bfs(source[0], source[1], true) && bfs(target[0], target[1], false);
    }

    bool bfs(int startX, int startY, bool isSource) {
        unordered_set<long long> vis;
        queue<long long> que;
        que.push(startX * 1e6 + startY);
        vis.insert(startX * 1e6 + startY);
        while(!que.empty() && vis.size() <= maxPoint) {
            long long x = que.front() / 1e6;
            long long y = que.front() % (long long) (1e6);
            que.pop();
            for(int i = 0; i < 4; i++) {
                long long nextX = x + dirs[i][0];
                long long nextY = y + dirs[i][1];
                if(nextX < 0 || nextX >= 1e6 || nextY < 0 || nextY >= 1e6) {
                    continue;
                }
                if(vis.count(nextX * 1e6 + nextY)) {
                    continue;
                }
                if(set.count(nextX * 1e6 + nextY)) {
                    continue;
                }
                if(isArrive(isSource, nextX, nextY)) {
                    return true;
                }
                que.push(nextX * 1e6 + nextY);
                vis.insert(nextX * 1e6 + nextY);
            }
        }
        return vis.size() > maxPoint;
    }

    bool isArrive(bool isSource, long long x, long long y) {
        if(isSource && x == target[0] && y == target[1]) {
            return true;
        }
        if(!isSource && x == source[0] && y == source[1]) {
            return true;
        }
        return false;
    }
};

// 2022.07.07
// bfs
class Solution {
public:
    vector<int> source;
    vector<int> target;
    vector<vector<int>> blocked;
    int maxVis;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<long long> set;
    bool isArrive(bool isSource, long long x, long long y) {
        if(isSource) {
            if(x == target[0] && y == target[1]) {
                return true;
            }
        }
        else {
            if(x == source[0] && y == source[1]) {
                return true;
            }
        }
        return false;
    }
    bool bfs(int startX, int startY, bool isSource) {
        unordered_set<long long> vis;
        queue<long long> que;
        vis.insert(startX * 1e6 + startY);
        que.push(startX * 1e6 + startY);
        while(!que.empty() && vis.size() <= maxVis) {
            long long x = que.front() / 1e6;
            long long y = que.front() % (long long)(1e6);
            que.pop();
            for(int i = 0; i < 4; i++) {
                long long nx = x + dirs[i][0];
                long long ny = y + dirs[i][1];
                if(nx < 0 || nx >= 1e6 || ny < 0 || ny >= 1e6) {
                    continue;
                }
                if(vis.count(nx * 1e6 + ny)) {
                    continue;
                }
                if(set.count(nx * 1e6 + ny)) {
                    continue;
                }
                if(isArrive(isSource, nx, ny)) {
                    return true;
                }
                vis.insert(nx * 1e6 + ny);
                que.push(nx * 1e6 + ny);
            }
        }
        return vis.size() > maxVis;
    }
    bool isEscapePossible(vector<vector<int>>& blocked_, vector<int>& source_, vector<int>& target_) {
        source = source_;
        target = target_;
        blocked = blocked_;
        int n = blocked.size();
        maxVis = (n + 2) * (n + 1) / 2;
        for(int i = 0; i < n; i++) {
            set.insert(blocked[i][0] * 1e6 + blocked[i][1]);
        }
        return bfs(source[0], source[1], true) && bfs(target[0], target[1], false);
    }
};

// 2022.07.19
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<long long> block;
    long long s;
    long long t;
    int n;
    int maxVal;
    long long getIdx(long long x, long long y) {
        return x * 1e6 + y;
    }
    bool update(queue<long long>& que, unordered_set<long long>& cur, unordered_set<long long>& other) {
        int size = que.size();
        if(cur.size() >= maxVal) {
            return true;
        }
        for(int i = 0; i < size; i++) {
            long long x = que.front() / 1e6;
            long long y = que.front() % (long long) 1e6;
            if(other.count(que.front())) {
                return true;
            }
            que.pop();
            for(int i = 0; i < 4; i++) {
                long long nx = x + dirs[i][0];
                long long ny = y + dirs[i][1];
                if(nx < 0 || nx >= 1e6 || ny < 0 || ny >= 1e6) {
                    continue;
                }
                if(block.count(getIdx(nx, ny))) {
                    continue;
                }
                if(cur.count(getIdx(nx, ny))) {
                    continue;
                }
                que.push(getIdx(nx, ny));
                cur.insert(getIdx(nx, ny));
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto it : blocked) {
            block.insert(getIdx(it[0], it[1]));
        }
        s = getIdx(source[0], source[1]);
        t = getIdx(target[0], target[1]);
        n = blocked.size();
        maxVal = (n + 1) * (n + 2) / 2;
        queue<long long> sque;
        queue<long long> tque;
        unordered_set<long long> sset;
        unordered_set<long long> tset;
        sque.push(s);
        sset.insert(s);
        tque.push(t);
        tset.insert(t);
        while(!sque.empty() && !tque.empty()) {
            if(sque.size() <= tque.size()) {
                if(update(sque, sset, tset)) {
                    return true;
                }
            }
            else {
                if(update(tque, tset, sset)) {
                    return true;
                }
            }
        }
        return false;
    }
};