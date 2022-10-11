// 2022.09.29
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pque;
        int sum = 0;
        for(auto& c : courses) {
            sum += c[0];
            pque.push(c[0]);
            if(sum > c[1]) {
                sum -= pque.top();
                pque.pop();
            }
        }
        return pque.size();
    }
};

// 2022.10.11
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int sum = 0;
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pque;
        for(auto& c : courses) {
            sum += c[0];
            pque.push(c[0]);
            if(sum > c[1]) {
                sum -= pque.top();
                pque.pop();
            }
        }
        return pque.size();
    }
};