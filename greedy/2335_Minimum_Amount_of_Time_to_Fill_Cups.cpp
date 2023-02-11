// 2023.02.11
// priority_queue
class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pque;
        for(auto& a : amount) {
            if(a != 0) {
                pque.push(a);
            }
        }
        int res = 0;
        while(pque.size() > 1) {
            int first = pque.top();
            pque.pop();
            int second = pque.top();
            pque.pop();
            if(first > 1) {
                pque.push(first - 1);
            }
            if(second > 1) {
                pque.push(second - 1);
            }
            res++;
        }
        if(!pque.empty()) {
            res += pque.top();
        }
        return res;
    }
};

// greedy
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if(amount[0] + amount[1] <= amount[2]) {
            return amount[2];
        }
        int t = amount[0] + amount[1] - amount[2];
        return (t + 1) / 2 + amount[2];
    }
};