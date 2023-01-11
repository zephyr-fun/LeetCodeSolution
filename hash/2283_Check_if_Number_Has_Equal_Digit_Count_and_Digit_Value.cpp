// 2023.01.11
class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int hash[10];
        memset(hash, 0, sizeof(hash));
        for(auto& c : num) {
            hash[c - '0']++;
        }
        for(int i = 0; i < n; i++) {
            if(num[i] - '0' != hash[i]) {
                return false;
            }
        }
        return true;
    }
};