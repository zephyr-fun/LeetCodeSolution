// 2022.09.07
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // end, cnt;
        int res = 0;
        int date = 0;
        int n = apples.size();
        while(date < n || !pq.empty()) {
            if(date < n && apples[date] > 0) {
                pq.push(make_pair(date + days[date] - 1, apples[date]));
            }
            while(!pq.empty() && date > pq.top().first) {
                pq.pop();
            }
            if(!pq.empty()) {
                auto [end, cnt] = pq.top();
                pq.pop();
                cnt--;
                if(cnt > 0 && end > date) {
                    pq.push(make_pair(end, cnt));
                }
                res++;
            }
            date++;
        }
        return res;
    }
};