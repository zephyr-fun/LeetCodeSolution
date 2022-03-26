// 2022.03.25
// simulate stack, O(m+n), O(m+n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sStack;
        string tStack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                sStack += s[i];
            }
            else if(!sStack.empty()){
                sStack.pop_back();
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#'){
                tStack += t[i];
            }
            else if(!tStack.empty()){
                tStack.pop_back();
            }
        }
        return sStack == tStack;
    }
};
//O(m+n), O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSharp = 0;
        int tSharp = 0;
        int i = s.size() - 1;
        int j = t.size() - 1;
        while(1){
            while(i >= 0){
                if(s[i] == '#'){
                    sSharp++;
                }
                else{
                    if(sSharp > 0){
                        sSharp--;
                    }
                    else break; // this char needs to be compared
                }
                i--; // mark
            }
            while(j >= 0){
                if(t[j] == '#'){
                    tSharp++;
                }
                else{
                    if(tSharp > 0){
                        tSharp--;
                    }
                    else break; // this char needs to be compared
                }
                j--; // mark
            }
            if(i < 0 || j < 0) break;
            if(s[i] != t[j]){
                return false;
            }
            i--;
            j--;
        }
        if(i == -1 && j == -1){
            return true;
        }
        return false;
    }
};