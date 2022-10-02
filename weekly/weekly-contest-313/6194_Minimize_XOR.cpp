// 2022.10.02
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int> n1(31, 0);
        vector<int> n2(31, 0);
        for(int i = 30; i >= 0; i--) {
            n1[i] = (num1 >> i) & 1;
            n2[i] = (num2 >> i) & 1;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < 31; i++) {
            if(n1[i] == 1) {
                cnt1++;
            }
            if(n2[i] == 1) {
                cnt2++;
            }
        }
        if(cnt1 == cnt2) {
            return num1;
        }
        else if(cnt1 < cnt2) {
            int idx = 0;
            int temp = cnt2 - cnt1;
            int res = 0;
            while(temp) {
                if(n1[idx] == 0) {
                    temp--;
                    res += (1 << idx);
                }
                idx++;
            }
            return res ^ num1;
        }
        else {
            int idx = 30;
            int res = 0;
            while(cnt2) {
                if(n1[idx] == 1) {
                    res += (n1[idx] << idx);
                    cnt2--;
                }
                idx--;
            }
            return res;
        }
    }
};