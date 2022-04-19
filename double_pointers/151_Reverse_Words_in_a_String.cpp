// 2022.03.31
class Solution {
public:
    void subReverse(string& s, int start, int end){
        while(start < end){
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            start++;
            end--;
        }
    }
    void removeExtraSpaces(string& s){
        int slow = 0;
        int fast = 0;
        // remove head spaces
        while(s[fast] == ' ' && s.size() > 0 && fast < s.size()){
            fast++;
        }
        // remove redundent spaces
        for(; fast < s.size(); fast++){
            if(fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' '){
                continue;
            }
            else{
                s[slow++] = s[fast];
            }
        }
        // remove tail spaces
        if(slow - 1 > 0 && s[slow - 1] == ' '){
            s.resize(slow - 1);
        }
        else{
            s.resize(slow);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        subReverse(s, 0, s.size() - 1);
        for(int left = 0, right = 0; right < s.size(); right++){
            while(right < s.size() && s[right] != ' '){
                right++;
            }
            subReverse(s, left, right - 1);
            left = right + 1;
        }
        return s;
    }
};

// 2022.04.19
class Solution {
public:
    void subReverse(string& s, int start, int end) {
        while(start < end) {
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            start++;
            end--;
        }
    }
    void removeExtraSpaces(string& s) {
        int slow = 0;
        int fast = 0;
        while(s.size() > 0 && fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        for(; fast < s.size(); fast++) {
            if(fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
                continue;
            }
            else {
                s[slow] = s[fast];
                slow++;
            }
        }
        if(slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        }
        else {
            s.resize(slow);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        int left = 0;
        int right = 0;
        while(right < s.size()) {
            while(s[right] != ' ' && right < s.size()) {
                right++;
            }
            subReverse(s, left, right - 1);
            left = right + 1;
            right++;
        }
        subReverse(s, 0, s.size() - 1);
        return s;
    }
};