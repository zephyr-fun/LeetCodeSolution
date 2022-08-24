// 2022.08.24
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            if(target[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }
};

// optim
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int res = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[target[i]]++;
            if(map[target[i]] == 1) {
                res++;
            }
            map[arr[i]]--;
            if(map[arr[i]] == 0) {
                res--;
            }
        }
        return res == 0;
    }
};