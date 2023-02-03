// 2022.08.13
// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         int res = 1;
//         for(int i = n - 1; i >= 0; i--) {
//             vector<int> temp;
//             while(!st.empty() && arr[i] <= st.top()) {
//                 temp.emplace_back(st.top());
//                 st.pop();
//             }
//             if(temp.size()) {
//                 res++;
//                 temp.clear();
//             }
//             st.push(arr[i]);
//         }
//         return res; 
//     }
// };
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // store the max value of a chunk in the stack
        // in which case can you add a new number to current case
        // if num >= st.top(), num can be a single chunk, and the chunk's max value is num
        // if num < st.top(), find the most close max value to have num in this chunk, and make it and all behind a whole
        stack<int> st;
        for (auto &num : arr) {
            if (st.empty() || num >= st.top()) {
                st.emplace(num);
            } else {
                int mx = st.top();
                st.pop();
                while (!st.empty() && st.top() > num) {
                    st.pop();
                }
                st.emplace(mx);
            }
        }
        return st.size();
    }
};

// 2023.02.03
// O(n)
// 是上面写法的优化版本，在最初用cur合并if-else逻辑
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for(auto& num : arr) {
            int cur = num;
            while(!st.empty() && st.top() > num) {
                cur = max(cur, st.top());
                st.pop();
            }
            st.push(cur);
        }
        return st.size();
    }
};

// O(nlogn)
// tot用来即使更新map中的匹配程度
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        int n = arr.size();
        int res = 0;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            int a = arr[i];
            int b = sorted[i];
            if(!map.count(a) || map[a] == 0) {
                tot++;
            }
            map[a]++;
            map[b]--;
            if(map[b] == 0) {
                tot--;
            }
            if(tot == 0) {
                res++;
            }
        }
        return res;
    }
};