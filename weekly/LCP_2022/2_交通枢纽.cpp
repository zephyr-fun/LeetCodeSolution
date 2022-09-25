// 2022.09.24
class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        int in[1007];
        int out[1007];
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        unordered_set<int> set;
        for(auto& p : path) {
            out[p[0]]++;
            in[p[1]]++;
            set.insert(p[0]);
            set.insert(p[1]);
        }
        int tot = set.size();
        for(int i = 0; i < 1007; i++) {
            if(in[i] == tot - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};