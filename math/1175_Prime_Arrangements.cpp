// 2022.06.30
// a! * b!
class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> vis(n + 1, false);
        int num = 0;
        for(int i = 2; i <= n; i++) {
            if(vis[i] == false) {
                num++;
                int temp = i;
                while(temp <= n) {
                    vis[temp] = true;
                    temp += i;
                }
            }
        }
        long long res = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <= num; i++) {
            res = res * i % mod;
        }
        for(int i = 1; i <= n - num; i++) {
            res = res * i % mod;
        }
        return int(res);
    }
};