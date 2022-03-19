// 2022.03.19
// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(needle, next);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
    void getNext(string& tar, int* next){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < tar.size(); i++){
            while(j > 0 && tar[i] != tar[j]){
                j = next[j - 1];
            }
            if(tar[i] == tar[j]){
                j++;
            }
            next[i] = j;
        }
    }
};