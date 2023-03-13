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

// 2023.03.13
// 对于engry，需要最少更改初始化多少，才能满足任意时刻的值都大于0，只需要将缺口最大的值弥补即可
class Solution {
public:
    int minNumberOfHours(int ieng, int iexp, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ensum = accumulate(energy.begin(), energy.end(), 0);
        ensum = ieng - ensum;
        ensum = ensum > 0 ? 0 : abs(ensum) + 1;
        int diffexp = iexp;
        for(int i = 0; i < n; i++) {
            diffexp = min(diffexp, iexp - experience[i]);
            iexp += experience[i];
        }
        diffexp = diffexp > 0 ? 0 : abs(diffexp) + 1;
        return ensum + diffexp;
    }
};