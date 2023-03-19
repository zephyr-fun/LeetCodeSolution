// 2023.03.19
// bfs
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string res = s;
        unordered_set<string> vis{{s}};
        queue<string> que{{s}};
        while(!que.empty()) {
            s = que.front();
            que.pop();
            res = min(res, s);
            string t1 = s;
            for(int i = 1; i < n; i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            string t2 = s.substr(n - b) + s.substr(0, n - b);
            for(auto& t : {t1, t2}) {
                if(!vis.count(t)) {
                    vis.insert(t);
                    que.push(t);
                }
            }
        }
        return res;
    }
};