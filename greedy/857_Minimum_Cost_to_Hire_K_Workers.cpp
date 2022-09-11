// 2022.09.11
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        int id[n];
        int sum_q = 0;
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) { // [&] capture outer value by &
            return wage[i] * quality[j] < wage[j] * quality[i];
        });
        priority_queue<int> pq;
        for(int i = 0; i < k; i++) {
            pq.push(quality[id[i]]);
            sum_q += quality[id[i]];
        }
        double res = sum_q * ((double) wage[id[k - 1]] / quality[id[k - 1]]);
        for(int i = k; i < n; i++) {
            if(int q = quality[id[i]]; q < pq.top()) {
                sum_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                res = min(res, sum_q * ((double) wage[id[i]] / q));
            }
        }
        return res;
    }
};