// 2023.01.19
class Solution {
public:
    bool check(char c){
        string temp = "!@#$%^&*()-+";
        for(int i = 0; i<temp.size();i++){
            if(c==temp[i])
                return true;
        }
        return false;
    }
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8)
            return false;
        bool upperflag = false;
        bool lowerflag = false;
        bool numflag = false;
        bool speflag = false;
        password=' '+password;
        for(int i=1; i<password.size();i++){
            char cur=password[i];
            if(cur>='0'&&cur<='9')
                numflag=true;
            if(cur>='a'&&cur<='z')
                lowerflag=true;
            if(cur>='A'&&cur<='Z')
                upperflag=true;
            if(check(cur))
                speflag=true;
            if(password[i-1]==cur)
                return false;
        }
        return numflag&&lowerflag&&upperflag&&speflag;
    }
};