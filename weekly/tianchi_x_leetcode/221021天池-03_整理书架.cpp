// 2022.10.22
class Solution {
public:
    vector<int> arrangeBookshelf(vector<int>& order, int limit) {
        int n = order.size();
        unordered_map<int, int> left;
        unordered_map<int, int> cnt_st;
        for(int i = 0; i < n; i++) {
            left[order[i]]++;
        }
        vector<int> res; // functions as a stack
        for(int i = 0; i < n; i++) {
            if(cnt_st[order[i]] == limit) {
                left[order[i]] -= 1;
                continue;
            }
            while(!res.empty() && res.back() > order[i] && left[res.back()] > limit) {
                left[res.back()]--;
                cnt_st[res.back()]--;
                res.pop_back();
            }
            cnt_st[order[i]]++;
            res.emplace_back(order[i]);
        }
        return res;
    }
};