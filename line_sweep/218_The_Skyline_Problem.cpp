// 2022.10.18
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ps;
        for(auto& build : buildings) {
            ps.emplace_back(make_pair(build[0], -build[2]));
            ps.emplace_back(make_pair(build[1], build[2]));
        }
        sort(ps.begin(), ps.end(), [](auto& a, auto& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        multiset<int, greater<int>> pque;
        pque.insert(0);
        vector<vector<int>> res;
        for(auto& build : ps) {
            int pos = build.first;
            int height = build.second;
            int top = *(pque.begin()); // served as prev record
            if(height < 0) {
                height = -height;
                if(height > top) {
                    res.emplace_back(initializer_list<int>{pos, height});
                }
                pque.insert(height);
            }
            else {
                pque.erase(pque.find(height));
                int temp = *(pque.begin());
                if(top > temp) {
                    res.emplace_back(initializer_list<int>{pos, temp});
                }
            }
        }
        return res;
    }
};