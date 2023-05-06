// 2023.05.06
// (a[0], b[0]) (a[0], b[1]) (a[0], b[2]) (a[0], b[3]) (a[0], b[k]) (a[0], b[m]) 
// (a[1], b[0]) (a[1], b[1]) (a[1], b[2]) (a[1], b[3]) (a[1], b[k]) (a[1], b[m]) 
//                                     ......
// (a[n], b[0]) (a[n], b[1]) (a[n], b[2]) (a[n], b[3]) (a[n], b[k]) (a[n], b[m]) 
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty()) {
            return {};
        }
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pque;
        for(int i = 0; i < m; i++) {
            pque.push({nums1[0] + nums2[i], 0, i});
        }
        vector<vector<int>> res;
        while(k-- && pque.size()) {
            auto t = pque.top();
            pque.pop();
            res.push_back({nums1[t[1]], nums2[t[2]]});
            if(t[1] + 1 < n) {
                pque.push({nums1[t[1] + 1] + nums2[t[2]], t[1] + 1, t[2]});
            }
        }
        return res;
    }
};