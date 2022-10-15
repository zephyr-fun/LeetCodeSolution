// 2022.10.15
class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int right = 0;
        int n = chars.size();
        int idx = 0;
        while(right < n) {
            while(right < n && chars[left] == chars[right]) {
                right++;
            }
            chars[idx] = chars[left];
            idx++;
            if(right - left > 1) {
                string temp = to_string(right - left);
                for(auto& t : temp) {
                    chars[idx] = t;
                    idx++;
                }
            }
            left = right;
        }
        return idx;
    }
};