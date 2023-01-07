// 2022.04.08
class Solution{
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for(auto num : nums){
            ab ^= num;
        }
        int i;
        for(i = 0; i < 32; i++){
            if(ab & 1 << i){
                break;
            }
        }
        int resa = 0;
        int resb = 0;
        for(auto num : nums){
            if(num & 1 << i){
                resa ^= num;
            }
            else{
                resb ^= num;
            }
        }
        return {resa, resb};
    }
};

// 2023.01.07
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(auto& num : nums) {
            temp ^= num;
        }
        int cnt = 0;
        while(((1 << cnt) & temp) == 0) {
            cnt++;
        }
        int mask = 1 << cnt;
        vector<int> num1;
        vector<int> num2;
        for(auto num : nums) {
            if(num & mask) {
                num1.emplace_back(num);
            }
            else {
                num2.emplace_back(num);
            }
        }
        vector<int> res(2, 0);
        for(auto& num : num1) {
            res[0] ^= num;
        }
        for(auto& num : num2) {
            res[1] ^= num;
        }
        return res;
    }
};