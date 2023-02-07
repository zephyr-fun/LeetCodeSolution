// 2023.02.07
// hh:mm 的处理方法通常是转化为分钟数
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> map;
        for(int i = 0; i < keyName.size(); i++) {
            auto name = keyName[i];
            auto time = keyTime[i];
            int h;
            int m;
            sscanf(time.c_str(), "%d:%d", &h, &m);
            int t = h * 60 + m;
            map[name].emplace_back(t);
        }
        vector<string> res;
        for(auto [name, ts] : map) {
            int n = ts.size();
            sort(ts.begin(), ts.end());
            if(n > 2) {
                for(int i = 0; i < n - 2; i++) {
                    if(ts[i + 2] - ts[i] <= 60) {
                        res.emplace_back(name);
                        break;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};