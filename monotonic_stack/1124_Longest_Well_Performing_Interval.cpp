// 2022.09.25
// T0 solution, with int[] replace unordered_map
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // unordered_map<int, int> map;
        int n = hours.size();
        int map[2 * n + 7];
        int offset = n + 1;
        memset(map, -1, sizeof(map));
        int res = 0;
        int sum = 0;
        for(int i = 0; i < hours.size(); i++) {
            if(hours[i] > 8) {
                sum++;
            }
            else {
                sum--;
            }
            if(sum > 0) {
                res = i + 1;
            }
            else {
                if(map[sum - 1 + offset] != -1) {
                    res = max(res, i - map[sum - 1 + offset]);
                }
                if(map[sum + offset] == -1) {
                    map[sum + offset] = i;
                }
            }
        }
        return res;
    }
};

// monotonic stack
