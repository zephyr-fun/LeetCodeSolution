// 2023.02.23
// dfs with map
class Solution {
public:
    unordered_map<long long, int> map;
    int dfs(long long cur) {
        if(cur == 1) {
            return 0;
        }
        if(map.count(cur)) {
            return map[cur];
        }
        int res = (cur % 2 == 0 ? dfs(cur / 2) : min(dfs(cur - 1), dfs(cur + 1))) + 1;
        map[cur] = res;
        return res;
    }
    int integerReplacement(int n) {
        return dfs(n * 1LL);
    }
};

// bfs with map
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) {
            return 0;
        }
        unordered_map<long long, int> map;
        queue<long long> que;
        que.push(n * 1LL);
        map[n * 1LL] = 0;
        while(!que.empty()) {
            long long cur = que.front();
            que.pop();
            int step = map[cur];
            vector<long long> ns;
            if(cur % 2 == 0) {
                ns.emplace_back(cur / 2);
            }
            else {
                ns.emplace_back(cur + 1);
                ns.emplace_back(cur - 1);
            }
            for(auto x : ns) {
                if(x == 1) {
                    return step + 1;
                }
                if(!map.count(x)) {
                    que.push(x);
                    map[x] = step + 1;
                }
            }
        }
        return -1;
    }
};

// bit operation
class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long long cur = n * 1LL;
        while(cur != 1) {
            if(cur % 2 == 0) {
                cur >>= 1;
            }
            else {
                if(cur != 3 && (cur >> 1) & 1 == 1) {
                    cur++;
                }
                else {
                    cur--;
                }
            }
            res++;
        }
        return res;
    }
};