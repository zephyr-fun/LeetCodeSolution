// 2022.09.20
// bfs
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if(s1 == s2) {
            return 0;
        }
        queue<pair<string, int>> que;
        que.push(make_pair(s1, 0));
        unordered_set<string> set;
        set.insert(s1);
        int n = s1.size();
        int step = 1;
        while(true) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [cur, pos] = que.front();
                que.pop();
                while(pos < n && cur[pos] == s2[pos]) {
                    pos++;
                }
                for(int j = pos + 1; j < n; j++) {
                    if(cur[j] != s2[j] && cur[j] == s2[pos]) {
                        swap(cur[j], cur[pos]);
                        if(cur == s2) {
                            return step;
                        }
                        if(!set.count(cur)) {
                            que.push(make_pair(cur, pos + 1));
                            set.insert(cur);
                        }
                        swap(cur[j], cur[pos]);
                    }
                }
            }
            step++;
        }
    }
};

//https://leetcode.cn/problems/k-similar-strings/solution/xiang-si-du-wei-k-de-zi-fu-chuan-by-leet-8z10/
// dfs

// dp