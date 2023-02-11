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

// 2022.09.23
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // end, cnt
        int n = apples.size();
        int res = 0;
        int day = 0;
        while(day < n || !pq.empty()) {
            if(day < n && apples[day] > 0) {
                pq.push(make_pair(day + days[day] - 1, apples[day]));
            }
            while(!pq.empty() && day > pq.top().first) {
                pq.pop();
            }
            if(!pq.empty()) {
                auto [end, cnt] = pq.top();
                pq.pop();
                cnt--;
                if(cnt > 0 && end > day) {
                    pq.push(make_pair(end, cnt));
                }
                res++;
            }
            day++;
        }
        return res;
    }
};

// 2023.02.11
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = apples.size();
        int day = 0;
        int res = 0;
        // [end, cnt]
        while(day < n || !pq.empty()) {
            if(day < n && apples[day] > 0) {
                pq.push(make_pair(day + days[day] - 1, apples[day]));
            }
            while(!pq.empty() && day > pq.top().first) {
                pq.pop();
            }
            if(!pq.empty()) {
                auto [end, cnt] = pq.top();
                pq.pop();
                cnt--;
                if(cnt > 0 && end > day) {
                    pq.push(make_pair(end, cnt));
                }
                res++;
            }
            day++;
        }
        return res;
    }
};