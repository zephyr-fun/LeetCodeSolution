// 2023.02.23
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> a = {0, 1};
        for(int i = 1; i < n; i++) {
            vector<int> b = a;
            for(int j = a.size() - 1; j >= 0; j--) {
                b.emplace_back(a[j] + (1 << i));
            }
            a = b;
        }
        for(auto& x : a) {
            x ^= start;
        }
        return a;
    }
};