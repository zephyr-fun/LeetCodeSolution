// 2023.01.10
// euler graph
class Solution {
public:
    int k;
    unordered_set<string> set;
    string res = "";

    void dfs(string u) {
        for(int i = 0; i < k; i++) {
            string v = u + to_string(i);
            if(!set.count(v)) {
                set.insert(v);
                dfs(v.substr(1));
                res += to_string(i);
            }
        }
    }

    string crackSafe(int n, int _k) {
        k = _k;
        string start(n - 1, '0');
        dfs(start);
        return res + start;
    }
};

// int replace string

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<int> vis; // revord edge
        int mod = pow(10, n - 1);
        string res;
        function<void(int)> dfs = [&](int u) {
            for(int x = 0; x < k; x++) {
                int e = u * 10 + x;
                if(!vis.count(e)) {
                    vis.insert(e);
                    dfs(e % mod);
                    res += (x + '0');
                }
            }
        };
        dfs(0);
        res += string(n - 1, '0');
        return res;
    }
};