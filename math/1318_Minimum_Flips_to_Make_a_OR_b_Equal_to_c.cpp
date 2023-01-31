// 2023.01.31
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int vis[32];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 32; i++) {
            if((a >> i) & 1) {
                vis[i]++;
            }
            if((b >> i) & 1) {
                vis[i]++;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if((c >> i) & 1) {
                res += vis[i] == 0 ? 1 : 0;
            }
            else {
                res += vis[i];
            }
        }
        return res;
    }
};

// optim space
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a || b || c) {
            int low_a = a & 1;
            int low_b = b & 1;
            int low_c = c & 1;
            if(low_c == 0) {
                res += low_a + low_b;
            }  
            else if(low_c == 1) {
                res += (low_a == 0 && low_b == 0);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
};