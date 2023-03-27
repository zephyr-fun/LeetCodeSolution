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

// 2023.03.27
// meaningless version
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) == string::npos ? -1 : haystack.find(needle);
    }
};

// KMP
class Solution {
public:
    // 找到前缀和后缀的最大重合值，自身匹配
    void getNext(string& t, int* next) {
        next[0] = 0;
        int left = 0;
        for(int right = 1; right < t.size(); right++) {
            while(left > 0 && t[left] != t[right]) {
                left = next[left - 1];
            }
            if(t[left] == t[right]) {
                left++;
            }
            next[right] = left;
        }
    }
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m == 0) {
            return 0;
        }
        int next[m];
        getNext(t, next);
        int j = 0;
        // 与暴力相比，i从不回退，j尽可能少的回退（更多地利用之前s和t的匹配情况加上t自身匹配的信息来少回退）
        for(int i = 0; i < n; i++) {
            while(j > 0 && s[i] != t[j]) {
                j = next[j - 1];
            }
            if(s[i] == t[j]) {
                j++;
            }
            if(j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};