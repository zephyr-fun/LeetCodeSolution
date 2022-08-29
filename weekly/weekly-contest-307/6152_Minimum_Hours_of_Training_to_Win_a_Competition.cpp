// 2022.08.29 sorted
class Solution {
public:
    int minNumberOfHours(int ien, int iex, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ensum = 0;
        int ex = iex;
        for(int i = 0; i < n; i++) {
            ensum += energy[i];
        }
        ensum = ien - ensum;
        ensum = ensum > 0 ? 0 : abs(ensum) + 1;
        for(int i = 0; i < n; i++) {
            ex = min(ex, iex - experience[i]);
            iex = iex + experience[i];
        }
        ex = ex > 0 ? 0 : abs(ex) + 1;
        return ensum + ex;
    }
};