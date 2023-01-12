// 2022.10.22
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string st;
        unordered_map<char, bool> ins;
        unordered_map<int, int> last;
        for(int i = 0; i < n; i++) {
            last[s[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            if(ins[s[i]]) {
                continue;
            }
            while(!st.empty() && st.back() > s[i] && last[st.back()] > i) {
                ins[st.back()] = false;
                st.pop_back();
            }
            st += s[i];
            ins[s[i]] = true;
        }
        return st;
    }
};

// 2023.01.12
class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, bool> is_used;
        unordered_map<char, int> last;
        string st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            last[s[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            if(is_used[s[i]]) {
                continue;
            }
            while(!st.empty() && st.back() > s[i] && last[st.back()] > i) {
                is_used[st.back()] = false;
                st.pop_back();
            }
            st += s[i];
            is_used[s[i]] = true;
        }
        return st;
    }
};

// use hash
// https://leetcode.cn/problems/remove-duplicate-letters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-4/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, int> map;
        for(auto c : s) {
            map[c]++;
        }
        string st = "";
        for(auto& c : s) {
            if(!st.empty()) {
                if(st.find(c) < st.size()) {
                    map[c]--;
                    continue;
                }
            }
            while(!st.empty() && c < st.back() && map[st.back()] > 1) {
                map[st.back()]--;
                st.pop_back();
            }
            st += c;
        }
        return st;
    }
};