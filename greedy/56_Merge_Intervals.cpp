// 2022.04.07
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0){
            return res;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

// 2022.07.19
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i + 1 < n && intervals[i + 1][0] <= end) {
                i++;
                end = max(end, intervals[i][1]);
            }
            res.emplace_back(initializer_list<int>{start, end});
        }
        return res;
    }
};

// 2022.09.16
// yxc version templete
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int st = -1;
        int ed = -1;
        for(auto& it : intervals) {
            if(it[0] > ed) {
                if(ed != -1) {
                    res.emplace_back(initializer_list<int>({st, ed}));
                }
                st = it[0];
                ed = it[1];
            }
            else {
                ed = max(ed, it[1]);
            }
        }
        if(ed != -1) {
            res.emplace_back(initializer_list<int>({st, ed}));
        }
        return res;
    }
};