// 2023.03.15
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> in(n, 0);
        vector<unordered_set<int>> g(n); 
        for(const auto& road : roads) {
            in[road[0]]++;
            in[road[1]]++;
            g[road[0]].insert(road[1]);
            g[road[1]].insert(road[0]);
        }
        int first = -1;
        int second = -2;
        for(auto& i : in) {
            if(i > first) {
                second = first;
                first = i;
            }
            else if (i > second) {
                second = i;
            }
        }
        vector<int> firstList;
        vector<int> secondList;
        for(int i = 0; i < n; i++) {
            if(in[i] == first) {
                firstList.emplace_back(i);
            }
            else if(in[i] == second) {
                secondList.emplace_back(i);
            }
        }
        if(firstList.size() == 1) {
            int u = firstList[0];
            for(auto v : secondList) {
                if(!g[u].count(v)) {
                    return first + second;
                }
            }
            return first + second - 1;
        }
        else {
            int m = roads.size();
            // 假设入度最多的城市有 x 个， 那么要想保证这 x 个城市两两之间都有直连，
            // 最少需要 x * (x - 1) / 2 条路径，
            // 如果所需路径 x * (x - 1) / 2 大于已有路径 m ，那必然存在两个城市之间没有直连路径，
            // 那么最大可以直接返回 first * 2
            if(firstList.size() * (firstList.size() - 1) / 2 > m) {
                return first * 2;
            }
            for(int u : firstList) {
                for(int v : firstList) {
                    if(u != v && !g[u].count(v)) {
                        return first * 2;
                    }
                }
            }
            return first * 2 - 1;
        }
    }
};