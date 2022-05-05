// 2022.05.05
// memory search
class Solution {
public:
    int mod = 1000000007;
    int cache[105][205];
    int size;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        size = locations.size();
        memset(cache, -1, sizeof(cache));
        return dfs(locations, start, finish, fuel);
    }
    int dfs(vector<int>& locations, int start, int finish, int fuel) {
        // if we already searched the sub task, return results
        if(cache[start][fuel] != -1) {
            return cache[start][fuel];
        }
        // if we run out of the fuel, and we are not at the finish point
        if(fuel == 0 && start != finish) {
            cache[start][fuel] = 0;
            return 0;
        }
        // if we still have fuel, but can't go any where
        bool hasNext = false;
        for(int i = 0; i < locations.size(); i++) {
            if(i != start) {
                if(abs(locations[i] - locations[start]) <= fuel) {
                    hasNext = true;
                    break;
                }
            }
        }
        if(fuel != 0 && !hasNext) {
            int remain = cache[start][fuel] = start == finish ? 1 : 0;
            return remain;
        }
        // if we are already at the finish point, conut 1
        int sum = start == finish ? 1 : 0;
        for(int i = 0; i < size; i++) {
            if(i != start) {
                if(abs(locations[i] - locations[start]) <= fuel) {
                    sum += dfs(locations, i, finish, fuel - abs(locations[i] - locations[start]));
                    sum %= mod;
                }
            }
        }
        cache[start][fuel] = sum;
        return sum;
    }
};

// dp
