// 2022.07.23
// map version
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> map;
        sort(arr.begin(), arr.end(), [](int& a, int& b) {
            return abs(a) < abs(b);
        });
        for(auto ar : arr) {
            if(map[ar] > 0) {
                map[ar]--;
            }
            else {
                map[ar * 2]++;
            }
        }
        for(auto [k, v] : map) {
            if(v > 0) {
                return false;
            }
        }
        return true;
    }
};

// array version
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int tot = 4 * 1e5 + 7;
        int s[tot];
        memset(s, 0, sizeof(s));
        sort(arr.begin(), arr.end(), [](int& a, int& b) {
            return abs(a) < abs(b);
        });
        int mod = 2e5;
        for(auto ar : arr) {
            if(s[ar + mod] > 0) {
                s[ar + mod]--;
            }
            else {
                s[ar * 2 + mod]++;
            }
        }
        for(int i = 0; i < tot; i++) {
            if(s[i] > 0) {
                return false;
            }
        }
        return true;
    }
};