// 2023.02.19
// sort by ratio change
class Solution {
public:
    struct Cmp {
        constexpr bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return (long long) (b.second + 1) * b.second * (a.second - a.first) < (long long) (a.second + 1) * a.second * (b.second - b.first);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pque;
        for(auto& c : classes) {
            pque.push(make_pair(c[0], c[1]));
        }
        while(extraStudents) {
            auto [pass, tot] = pque.top();
            pque.pop();
            pass++;
            tot++;
            extraStudents--;
            pque.push(make_pair(pass, tot));
        }
        int n = classes.size();
        double temp = 0;
        while(!pque.empty()) {
            auto [pass, tot] = pque.top();
            pque.pop();
            temp += (double) pass / (double) tot; // temp += 1.0 * pass / tot;
        }
        return temp / n;
    }
};