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
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2 * k)){
            if(i + k < s.size()){
                subReverse(s, i, i + k - 1);
                continue;
            }
            subReverse(s, i, s.size() - 1);
        }
        return s;
    }
};