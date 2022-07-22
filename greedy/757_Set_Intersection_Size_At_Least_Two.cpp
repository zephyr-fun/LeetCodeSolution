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