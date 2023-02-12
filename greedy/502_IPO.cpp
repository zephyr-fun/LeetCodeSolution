// 2023.02.12
// greater than O(nlogn)
class Solution {
public:
    struct Cmp{
        constexpr bool operator() (pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int curCap = w;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pque;
        int n = profits.size();
        for(int i = 0; i < n; i++) {
            pque.push(make_pair(profits[i], capital[i]));
        }
        while(k && !pque.empty()) {
            vector<pair<int, int>> temp;
            while(!pque.empty() && curCap < pque.top().second) {
                temp.emplace_back(pque.top());
                pque.pop();
            }
            if(pque.empty() || k == 0) {
                break;
            }
            curCap += pque.top().first;
            pque.pop();
            for(auto t : temp) {
                pque.push(t);
            }
            k--;
        }
        return curCap;
    }
};

// sort
class Solution {
public:
    struct Cmp{
        constexpr bool operator() (pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int curCap = w;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pque;
        int n = profits.size();
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++) {
            temp.emplace_back(make_pair(profits[i], capital[i]));
        }
        sort(temp.begin(), temp.end(), [] (pair<int, int>& a, pair<int, int>& b) {
            if(a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        int idx = 0;
        while(k) {
            while(idx < n && curCap >= temp[idx].second) {
                pque.push(temp[idx]);
                idx++;
            }
            if(pque.empty()) {
                break;
            }
            curCap += pque.top().first;
            pque.pop();
            k--;
        }
        return curCap;
    }
};