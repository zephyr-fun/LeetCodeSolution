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

// 2023.09.13
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int sum = 0;
        sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pque;
        for (auto& c : courses) {
            sum += c[0];
            pque.push(c[0]); // emplace is much faster than push
            if (sum > c[1]) {
                sum -= pque.top();
                pque.pop();
            }
        }
        return pque.size();
    }
};

// another way to optim is considering every branches
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int sum = 0;
        sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pque;
        for (auto& c : courses) {
            if (c[0] > c[1]) {
                continue;
            }
            if (c[0] + sum > c[1]) {
                if (c[0] < pque.top()) {
                    sum = sum - pque.top() + c[0];
                    pque.pop();
                    pque.emplace(c[0]);
                }
            }
            else {
                pque.emplace(c[0]);
                sum += c[0];
            }
        }
        return pque.size();
    }
};

// 2023.09.21
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int sum = 0;
        priority_queue<int> pque;
        for (auto& c : courses) {
            sum += c[0];
            pque.push(c[0]);
            if (sum > c[1]) {
                sum -= pque.top();
                pque.pop();
            }
        }
        return pque.size();
    }
};