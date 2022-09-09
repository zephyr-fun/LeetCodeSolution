// 2022.09.09
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string res = "";
        for(auto num : nums) {
            res += to_string(num);
        }
        int idx = 0;
        while(idx < res.size() - 1) {
            if(res[idx] == '0') {
                idx++;
            }
            else {
                break;
            }
        }
        return res.substr(idx);
    }
};

// while is not needed
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string res = "";
        for(auto num : nums) {
            res += to_string(num);
        }
        if(res[0] == '0') {
            return "0";
        }
        return res;
    }
};