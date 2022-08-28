// 2022.08.28
// plain version
typedef long long int64;
class Solution {
public:
    int preimageSizeFZF(int k) {
        if(k <= 1) {
            return 5;
        }
        // cout << f(k) << "," << f(k - 1) << endl;
        return (int)(f(k) - f(k - 1));
    }
    int64 f(int x) {
        if(x == 1) {
            return 9;
        }
        int64 l = 0;
        int64 r = 1e18;
        int64 pos = -1;
        while(l <= r) {
            int64 mid = l + (r - l) / 2;
            // cout << l << "," << r << "," << mid << endl;
            if(getCnt(mid) < x) {
                l = mid + 1;
            }
            else if(getCnt(mid) > x){
                r = mid - 1;
            }
            else {
                pos = mid;
                l = mid + 1;
            }
            
        }
        if(pos == -1) {
            return f(x - 1);
        }
        return pos;
    }
    int64 getCnt(int64 x) {
        int64 res = 0;
        while(x != 0) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }
};

// more clear version
typedef long long int64;
class Solution {
public:
    int preimageSizeFZF(int k) {
        if(k <= 1) {
            return 5;
        }
        // cout << f(k) << "," << f(k - 1) << endl;
        return (int)(f(k) - f(k - 1));
    }
    int64 f(int x) {
        int64 l = 0;
        int64 r = 1e18;
        int64 pos = -1;
        while(l <= r) {
            int64 mid = l + (r - l) / 2;
            // cout << l << "," << r << "," << mid << endl;
            if(getCnt(mid) <= x) {
                pos = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return pos;
    }
    int64 getCnt(int64 x) {
        int64 res = 0;
        while(x != 0) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }
};