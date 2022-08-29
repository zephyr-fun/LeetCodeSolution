// 2022.08.29 sorted
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string res = "";
        int n = s.size();
        vector<int> diff(n + 1, 0);
        diff[0] = s[0] - 'a';
        for(int i = 1; i < n; i++) {
            diff[i] = s[i] - s[i - 1];
        }
        for(auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int delta = shift[2] == 0 ? -1 : 1;
            diff[start] += delta;
            diff[end + 1] -= delta;
            // for(auto num : diff) {
            //     cout << num << ", ";
            // }
            // cout << endl;
        }
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur = cur + diff[i];
            while(cur < 0) {
                cur += 26;
            }
            cur = cur % 26;
            res += 'a' + cur;
        }
        return res;
    }
};