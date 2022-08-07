// 2022.08.07
class Solution {
public:
    int leastInterval(vector<char>& tasks, int len) {
        int n = tasks.size();
        int len1 = n;
        unordered_map<char, int> map;
        for(int i = 0; i < n; i++) {
            map[tasks[i]]++;
        }
        int maxVal = 0;
        int cnt = 0;
        for(auto [k, v] : map) {
            if(v > maxVal) {
                maxVal = v;
                cnt = 1;
            }
            else if(v == maxVal) {
                cnt++;
            }
        }
        int len2 = (maxVal - 1) * (len + 1) + cnt;
        return max(len1, len2);
    }
};