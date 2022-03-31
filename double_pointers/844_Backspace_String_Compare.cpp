// 2022.03.31
// stack
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

// space O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSharp = 0;
        int tSharp = 0;
        int sIndex = s.size() - 1;
        int tIndex = t.size() - 1;
        while(1){
            while(sIndex >= 0){
                if(s[sIndex] == '#'){
                    sSharp++;
                }
                else{
                    if(sSharp > 0){
                        sSharp--;
                    }
                    else{
                        break;
                    }
                }
                sIndex--;
            }
            while(tIndex >= 0){
                if(t[tIndex] == '#'){
                    tSharp++;
                }
                else{
                    if(tSharp > 0){
                        tSharp--;
                    }
                    else{
                        break;
                    }
                }
                tIndex--;
            }
            if(sIndex < 0 || tIndex < 0){
                break;
            }
            if(s[sIndex] != t[tIndex]){
                return false;
            }
            sIndex--;
            tIndex--;
        }
        if(sIndex == -1 && tIndex == -1){
            return true;
        }
        return false;
    }
};