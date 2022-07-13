// 2022.07.13
// mimic stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(res.size() == 0 || (res.back() > 0 && asteroids[i] > 0) || (res.back() < 0 && asteroids[i] < 0)) {
                res.emplace_back(asteroids[i]);
            }
            else {
                while(!res.empty() && abs(asteroids[i]) > abs(res.back()) && (res.back() > 0 && asteroids[i] < 0)) {
                    res.pop_back();
                }
                if(!res.empty() && abs(asteroids[i]) == abs(res.back()) && (res.back() > 0 && asteroids[i] < 0)) {
                    res.pop_back();
                    continue;
                }
                if(!res.empty() && abs(asteroids[i]) < abs(res.back()) && (res.back() > 0 && asteroids[i] < 0)) {
                    continue;
                }
                res.emplace_back(asteroids[i]);
            }
        }
        return res;
    }
};

// stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto as : asteroids) {
            bool ok = true;
            while(ok && !st.empty() && st.top() > 0 && as < 0) {
                int a = abs(st.top());
                int b = abs(as);
                if(a <= b) {
                    st.pop();
                }
                if(a >= b){
                    ok = false;
                }
            }
            if(ok) {
                st.push(as);
            }
        }
        int size = st.size();
        vector<int> res(size, 0);
        for(int i = size - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};