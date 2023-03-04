// 2023.03.04
// O(n^3) -> 2 * O(n^2)
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt[1 << 16];
        memset(cnt, 0, sizeof(cnt));
        for(auto& x : nums) {
            for(auto& y : nums) {
                cnt[x & y]++;
            }
        }
        int res = 0;
        for(int i = 0; i < (1 << 16); i++) {
            for(auto& num : nums) {
                if((num & i) == 0) {
                    res += cnt[i];
                }
            }
        }
        return res;
    }
};

// enumrate subset
// int m;
// int s = m;
// while(1) {
//     // op
//     s = (s - 1) & m;
//     if(s == m) {
//         break;
//     }
// }
// optim enumerate
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt[1 << 16];
        memset(cnt, 0, sizeof(cnt));
        for(auto& x : nums) {
            for(auto& y : nums) {
                cnt[x & y]++;
            }
        }
        int res = 0;
        for(auto& num : nums) {
            num ^= 0xffff;
            int s = num;
            while(1) {
                res += cnt[s];
                s = (s - 1) & num;
                if(s == num) {
                    break;
                }
            }
        }
        return res;
    }
};