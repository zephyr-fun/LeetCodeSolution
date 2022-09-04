// 2022.09.04
class Solution {
    typedef pair<int, int> pii;
    
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int ans = 0;
        deque<pii> q;
        long long sm = 0;
        // i 是 two pointers 区间的末尾，j 是 two pointers 区间的开头，区间包含 i 和 j
        for (int i = 0, j = 0; i < n; i++) {
            if (q.empty()) j = i;
            // 维护一个递减的单调队列，单调队列的头即为区间内的最大值
            while (!q.empty() && q.back().first <= chargeTimes[i]) q.pop_back();
            q.push_back(pii(chargeTimes[i], i));
            sm += runningCosts[i];
            // 增加 j 直到费用符合要求
            while (!q.empty() && q.front().first + (i - j + 1) * sm > budget) {
                if (j == q.front().second) q.pop_front();
                sm -= runningCosts[j];
                j++;
            }
            if (!q.empty()) ans = max(ans, i - j + 1);
        }
        return ans;
    }
};