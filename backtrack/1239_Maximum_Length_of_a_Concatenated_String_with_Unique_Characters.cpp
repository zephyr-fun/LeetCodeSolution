// 2022.07.26
// doesn't work, work now
// key point lies in 27-29
// start index
class Solution {
public:
    int res = 0;
    vector<string> arr;
    bool check(string a, string b) {
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                i++;
            }
            else if(a[i] > b[j]) {
                j++;
            }
            else {
                return false;
            }
        }
        return true;
    }
    void dfs(int u, string cur) {
        res = max(res, (int)cur.size());
        sort(cur.begin(), cur.end());
        for(int i = u; i < arr.size(); i++) { // key point
            if(check(cur, arr[i])) {
                dfs(i + 1, cur + arr[i]);
            }
        }
    }
    int maxLength(vector<string>& arr_) {
        for(auto a : arr_) {
            sort(a.begin(), a.end());
            if(unique(a.begin(), a.end()) == a.end()) {
                arr.emplace_back(a);
            }
        }
        dfs(0, "");
        return res;
    }
};

// whole 
// __builtin_popcount
class Solution {
public:
    vector<int> a;
    int res = 0;
    void dfs(int s, int mask) {
        res = max(res, __builtin_popcount(mask));
        for(int i = s; i < a.size(); i++) {
            if((mask & a[i]) == 0) {
                dfs(i + 1, mask | a[i]);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        for(auto x : arr) {
            int mask = 0;
            for(auto c : x) {
                mask |= 1 << (c - 'a');
            }
            if(__builtin_popcount(mask) == x.size()) {
                a.emplace_back(mask);
            }
        }
        dfs(0, 0);
        return res;
    }
};