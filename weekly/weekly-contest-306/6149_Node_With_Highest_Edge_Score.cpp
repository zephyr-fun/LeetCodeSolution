// 2022.08.14 contest 2022.08.15 update
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> ed(n, 0);
        for(int i = 0; i < n; i++) {
            ed[edges[i]] += (long long)i;
        }
        int res = -1;
        long long maxVal = -1;
        for(int i = 0; i < n; i++) {
            if(ed[i] > maxVal) {
                maxVal = ed[i];
                res = i;
            }
        }
        return res;
    }
};