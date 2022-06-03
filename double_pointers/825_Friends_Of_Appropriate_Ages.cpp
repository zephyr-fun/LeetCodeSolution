// 2022.06.03
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int res = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++) {
            while(left < i && !check(ages[left], ages[i])) {
                left++;
            }
            if(right < i) {
                right = i;
            }
            while(right < n && check(ages[right], ages[i])) {
                right++;
            }
            if(right > left) {
                res += right - left - 1;
            }
        }
        return res;
    }
    bool check(int x, int y) {
        if(y <= 0.5 * x + 7) {
            return false;
        }
        if(y > x) {
            return false;
        }
        if(y > 100 && x < 100) {
            return false;
        }
        return true;
    }
};