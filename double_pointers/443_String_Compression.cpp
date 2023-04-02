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

// 2023.04.02
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0;
        int right = 0;
        int idx = 0;
        while(right < n) {
            while(right < n && chars[right] == chars[left]) {
                right++;
            }
            int len = right - left;
            chars[idx++] = chars[left];
            if(len > 1) {
                string temp = to_string(len);
                for(auto& c : temp) {
                    chars[idx++] = c;
                }
            }
            left = right;
        }
        return idx;
    }
};