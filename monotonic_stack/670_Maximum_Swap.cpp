// 2022.09.13
class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int n = temp.size();
        int idx = 0;
        stack<int> st;
        while(idx < n) {
            if(st.empty() || temp[idx] <= temp[st.top()]) {
                st.push(idx);
                idx++;
            }
            else {
                break;
            }
        }
        if(idx == n) {
            return num;
        }
        int left;
        int right = idx;
        while(idx < n) {
            if(temp[idx] >= temp[right]) {
                right = idx;
            }
            idx++;
        }
        while(!st.empty() && temp[st.top()] < temp[right]) {
            left = st.top();
            st.pop();
        }
        swap(temp[left], temp[right]);
        return stoi(temp);
    }
};

// pure monotonic stack
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int left = n;
        int right = 0;
        int idx = 0;
        stack<int> st;
        while(idx < n) {
            while(!st.empty() && s[st.top()] < s[idx]) {
                int temp = st.top();
                st.pop();
                if(temp < left) {
                    left = temp;
                    right = idx;
                }
                if(temp == right) {
                    right = idx;
                }
            }
            if(right < n && s[idx] == s[right]) {
                right = idx;
            }
            st.push(idx);
            idx++;
        }
        if(left < n) {
            swap(s[left], s[right]);
            return stoi(s);
        }
        return num;
    }
};