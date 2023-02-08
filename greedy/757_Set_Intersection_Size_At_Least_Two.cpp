// 2022.07.22
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int cnt = 0;
        vector<int> q(1, -1);
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        for(auto it : intervals) {
            if(it[0] > q[cnt]) {
                cnt++;
                q.emplace_back(it[1] - 1);
                cnt++;
                q.emplace_back(it[1]);
            }
            else if(it[0] > q[cnt - 1]){
                cnt++;
                q.emplace_back(it[1]);
            }
        }
        return cnt;
    }
};

// 2023.02.08
// optim vector to maxi, submax and res
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        int maxi = -1;
        int submax = -1;
        int res = 0;
        for(auto& it : intervals) {
            int left = it[0];
            int right = it[1];
            if(left > maxi) {
                maxi = right;
                submax = right - 1;
                res += 2;
            }
            else if(left > submax) {
                submax = maxi;
                maxi = right;
                res += 1;
            }
        }
        return res;
    }
};