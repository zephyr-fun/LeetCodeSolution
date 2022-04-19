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
// 2022.03.31
// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(needle, next);
        int needleIndex = 0;
        for(int haystackIndex = 0; haystackIndex < haystack.size(); haystackIndex++){
            while(haystack[haystackIndex] != needle[needleIndex] && needleIndex > 0){
                needleIndex = next[needleIndex - 1];
            }
            if(haystack[haystackIndex] == needle[needleIndex]){
                needleIndex++;
            }
            if(needleIndex == needle.size()){
                return haystackIndex - needle.size() + 1;
            }
        }
        return -1;

    }
    void getNext(string& tar, int* next){
        next[0] = 0;
        int left = 0;
        for(int right = 1; right < tar.size(); right++){
            while(left > 0 && tar[left] != tar[right]){
                left = next[left - 1];
            }
            if(tar[left] == tar[right]){
                left++;
            }
            next[right] = left;
        }
    }
};

// 2022.04.19
class Solution {
public:
    void getNext(string& tar, int* next) {
        next[0] = 0;
        int left = 0;
        for(int right = 1; right < tar.size(); right++) {
            while(left > 0 && tar[left] != tar[right]) {
                left = next[left - 1];
            }
            if(tar[left] == tar[right]) {
                left++;
            }
            next[right] = left;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(needle, next);
        int needleIndex = 0;
        for(int haystackIndex = 0; haystackIndex < haystack.size(); haystackIndex++) {
            while(needleIndex > 0 && haystack[haystackIndex] != needle[needleIndex]) {
                needleIndex = next[needleIndex - 1];
            }
            if(haystack[haystackIndex] == needle[needleIndex]) {
                needleIndex++;
            }
            if(needleIndex == needle.size()) {
                return haystackIndex - needle.size() + 1;
            }
        }
        return -1;
    }
};