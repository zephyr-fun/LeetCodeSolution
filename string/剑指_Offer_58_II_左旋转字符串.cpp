// 2022.03.31
// same as kmp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        string doubleString = s + s;
        return doubleString.substr(n, size);
    }
};
// reverse
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
    string reverseLeftWords(string s, int n) {
        subReverse(s, 0, n - 1);
        subReverse(s, n, s.size() - 1);
        subReverse(s, 0, s.size() - 1);
        return s;
    }
};