// 2023.08.16
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_set<int> set;
        vector<int> res;
        int round = 1;
        int pos = 0;
        while (!set.count(pos)) {
            set.insert(pos);
            pos = (pos + round * k) % n;
            round++;
        }
        for (int i = 0; i < n; i++) {
            if(!set.count(i)) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};