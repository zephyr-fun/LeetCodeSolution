// 2022.08.18
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> temp(32, 0);
        for(auto& num : nums) {
            for(int i = 31; i >= 0; i--) {
                if(num & (1 << i)) {
                    temp[i] = (temp[i] + 1) % 3;
                }
            }
        }
        int res = 0;
        for(int i = 0; i <= 31; i++) {
            if(temp[i]) {
                res |= 1 << i;
            }
        }
        return res;
    }
};

//DFA
// https://wenku.baidu.com/view/e9460ad96729647d27284b73f242336c1eb930f0.html
// https://baike.baidu.com/item/%E5%8D%A1%E8%AF%BA%E5%9B%BE%E5%8C%96%E7%AE%80%E6%B3%95
// ^
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};