// 2022.09.04
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector<int> diff(26, -1);
        for(int i = 0; i < n; i++) {
            int u = s[i] - 'a';
            if(diff[u] != -1) {
                diff[u] = i - diff[u] - 1;
            }
            else {
                diff[u] = i;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(diff[i] != distance[i] && diff[i] != -1) {
                return false;
            }
        }
        return true;
    }
};