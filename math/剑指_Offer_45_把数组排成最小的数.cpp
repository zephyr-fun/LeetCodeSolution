// 2022.09.03
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string ab = to_string(a) + to_string(b);
            string ba = to_string(b) + to_string(a);
            for(int i = 0; i < ab.size(); i++) {
                if(ab[i] == ba[i]) {
                    continue;
                }
                return ab[i] < ba[i];
            }
            return false;
            // return stoi(to_string(a) + to_string(b)) < stoi(to_string(b) + to_string(a));
        });
        string res = "";
        for(int i = 0; i < n; i++) {
            res += to_string(nums[i]);
        }
        return res;
    }
};