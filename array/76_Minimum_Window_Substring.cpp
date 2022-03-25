class Solution {
public:
    //检查hs中是否包含了ht的全部字符以及个数
    bool check(unordered_map<char, int> &hs, unordered_map<char, int> &ht){
        for(unordered_map<char,int>::iterator it=ht.begin();it!=ht.end();it++){
            if(hs[it->first]<it->second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> hs; //用于保存字符串s的滑动窗口里元素出现次数
        unordered_map<char, int> ht; //保存字符串t中各元素出现次数

        int minlen = INT_MAX; //记录最小长度
        int ansL = -1; //子串的左边起点

        for(int i=0;i<t.size();i++) ht[t[i]]++; //遍历t，并统计各字符出现次数
        
        //滑动窗口，让j不断往右移动，找到一个满足条件的子串
        for(int i=0,j=0;i<=j&&j<s.size();){
            //如果滑动窗口内元素是空的并且j所指元素不在ht中，可以让i和j都先右移,直到碰见第一个元素在ht里面
            if(hs.empty()&&ht.find(s[j])==ht.end()){
                i++;
                j++;
            }
            //如果j处元素在ht中有，那么j处元素也需要保存到hs中
            if(ht.find(s[j])!=ht.end()) hs[s[j]]++; //往hs里面填充有效元素,非必要的不要放进去

            //如果此时hs已经包含了ht中全部字符，就需要让i往右移
            while(check(hs,ht)&&i<=j){
                //如果当前子串长度更小，则更新
                if(j-i+1<minlen){
                    minlen = j-i+1;
                    ansL = i; //记录起点
                }
                //如果i处元素在ht中有，将出现hs中对应出现次数-1
                if(ht.find(s[i])!=ht.end()) hs[s[i]]--; //元素出现次数减1
                i++; //i往右移
            }
            j++; //j继续右移
        }
        if(ansL==-1) return "";
        else{
            return s.substr(ansL, minlen);
        }
    }
};