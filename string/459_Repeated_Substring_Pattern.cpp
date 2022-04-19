// 2022.03.31
class Solution {
public:
    void getNext(string& s, int* next){
        next[0] = 0;
        int left = 0;
        for(int right = 1; right < s.size(); right++){
            while(left > 0 && s[left] != s[right]){
                left = next[left - 1];
            }
            if(s[left] == s[right]){
                left++;
            }
            next[right] = left;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0){
            return false;
        }
        int next[s.size()];
        getNext(s, next);
        int len = s.size();
        //cout << next[len - 1] ;
        if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0){
            return true;
        }
        return false;
    }
};

// 2022.04.19
class Solution {
public:
    void getNext(string& s, int* next) {
        next[0] = 0;
        int left = 0;
        for(int right = 1; right < s.size(); right++) {
            while(left > 0 && s[left] != s[right]) {
                left = next[left - 1];
            }
            if(s[left] == s[right]) {
                left++;
            }
            next[right] = left;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(s, next);
        int len = s.size();
        if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }
};