// 2022.06.13
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int an = a.size();
        int bn = b.size();
        int left = 1;
        int right = bn / an + 2;
        cout << right;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            string cura = "";
            int cnt = mid;
            while(cnt > 0) {
                cura += a;
                cnt--;
            }
            if(cura.find(b) != string::npos) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};