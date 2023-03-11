// 2023.03.11
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> last;
        int left = 0;
        int right = 0;
        int len = 0;
        last[0] = -1;
        int cur = 0;
        int n = array.size();
        for(int i = 0; i < n; i++) {
            if(array[i][0] >= '0' && array[i][0] <= '9') { // note ><= in string is not the same as char
                cur++;
            }
            else {
                cur--;
            }
            if(last.count(cur)) {
                if(i - last[cur] > len) {
                    left = last[cur] + 1;
                    right = i;
                    len = i - last[cur];
                }
            }
            else {
                last[cur] = i;
            }
        }
        return left == right ? vector<string> () : vector<string> (array.begin() + left, array.begin() + right + 1);
    }
};