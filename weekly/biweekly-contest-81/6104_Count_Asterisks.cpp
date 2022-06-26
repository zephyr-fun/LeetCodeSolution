// 2022.06.26
class Solution {
public:
    int countAsterisks(string s) {
        int res = 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='*'&&cnt%2!=1){
                res++;
            }
            else if(s[i]=='|'){
                cnt++;
            }
        }
        return res;
    }
};