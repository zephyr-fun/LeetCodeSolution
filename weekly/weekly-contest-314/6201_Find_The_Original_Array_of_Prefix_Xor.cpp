// 2022.10.09
// pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
// pref[i + 1] = arr[0] ^ arr[1] ^ ... ^ arr[i] ^ arr[i + 1]
// arr[i + 1] = pref[i + 1] ^ pref[i]
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n, 0);
        res[0] = pref[0];
        for(int i = 1; i < n; i++) {
            res[i] = pref[i] ^ pref[i - 1];
        }
        return res;
    }
};