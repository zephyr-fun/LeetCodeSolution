// 2023.06.10
class Solution {
public:
    // 理解错题意的check function
    // int check(string& s) {
    //     int cnt[26] = {0};
    //     int res = 0;
    //     int cur = 27;
    //     for(auto& c : s) {
    //         cnt[c - 'a']++;
    //         if(cnt[c - 'a'] > res) {
    //             res = cnt[c - 'a'];
    //             cur = c - 'a';
    //         }
    //         else if(cnt[c - 'a'] == res) {
    //             cur = c - 'a' > cur ? cur : c - 'a';
    //         }
    //     }
    //     return res;
    // }

    int check(string& s) {
        int cnt[26] = {0};
        for(auto& c : s) {
            cnt[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) {
                return cnt[i];
            }
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int> res(n, 0);
        vector<int> temp(m, 0);
        for(int i = 0; i < m; i++) {
            temp[i] = check(words[i]);
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < n; i++) {
            int cur = check(queries[i]);
            // 有问题的手撕二分
            // int left = 0;
            // int right = m - 1;
            // while(left <= right) {
            //     int mid = left + (right - left) / 2;
            //     if(temp[mid] > cur) {
            //         right = mid - 1;
            //     }
            //     else {
            //         left = mid + 1;
            //     }
            // }
            auto idx = upper_bound(temp.begin(), temp.end(), cur) - temp.begin();
            res[i] = m - idx;
        }
        return res;
    }
};