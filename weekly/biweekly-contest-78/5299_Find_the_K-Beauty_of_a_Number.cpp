// 2022.05.15
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string nums = to_string(num);
        if(nums.size() < k) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i <= nums.size() - k; i++) {
            int temp = stoi(nums.substr(i, k));
            if(temp == 0) {
                continue;
            }
            if(num % temp == 0) {
                res++;
            }
        }
        return res;
    }
};