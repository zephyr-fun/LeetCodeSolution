// 2022.03.27
// over time
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> res;
//         if(s.size() < p.size())
//             return res;
//         string pattern = p;
//         sort(pattern.begin(), pattern.end());
//         for(int i = 0; i < s.size() - p.size() + 1; i++){
//             string sub = s.substr(i, p.size());
//             sort(sub.begin(), sub.end());
//             if(sub == pattern){
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
// };
// sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size())
            return res;
        int sizeS = s.size();
        int sizeP = p.size();
        int pCount[26] = {0};
        for(int i = 0; i < sizeP; i++){
            pCount[p[i] - 'a']++;
        }
        int pIden = 0;
        for(int i = 0; i < 26; i++){
            if(pCount[i] != 0){
                pIden++;
            }
        }
        for(int left = 0, right = 0, sIden = 0; right < sizeS; right++){
            if(--pCount[s[right] - 'a'] == 0){
                sIden++;
            }
            if(right - left + 1 > sizeP && ++pCount[s[left++] - 'a'] == 1){
                sIden--;
            }
            if(pIden == sIden){
                res.push_back(left);
            }
            //cout << "piden" << pIden << "siden" << sIden;
        }
        return res;
    }
};
// 2022.03.29
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()){
            return res;
        }
        int count[26] = {0};
        // init p
        for(int i = 0; i < p.size(); i++){
            count[p[i] - 'a']++;
        }
        // init piden
        int pIden = 0;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                pIden++;
            }
        }
        // sliding window
        for(int left = 0, right = 0, sIden = 0; right < s.size(); right++){
            // more right
            if(--count[s[right] - 'a'] == 0){
                sIden++;
            }
            // reduce left
            if(right - left + 1 > p.size() && ++count[s[left++] - 'a'] == 1){
                sIden--;
            }
            // check
            if(sIden == pIden){
                res.push_back(left);
            }
        }
        return res;
    }
};

// 2022.04.18
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int map[26] = {0};
        for(int i = 0; i < p.size(); i++) {
            map[p[i] - 'a']++;
        }
        int pIden = 0;
        int sIden = 0;
        for(int i = 0; i < 26; i++) {
            if(map[i] > 0) {
                pIden++;
            }
        }
        for(int left = 0, right = 0; right < s.size(); right++) {
            if(--map[s[right] - 'a'] == 0) {
                sIden++;
            }
            if(right - left + 1 > p.size() && ++map[s[left++] - 'a'] == 1) {
                sIden--;
            }
            if(sIden == pIden) {
                res.push_back(left);
            }
        }
        return res;
    }
};

// 2022.10.13
class Solution {
public:
    bool isSame(int* smap, int* pmap) {
        for(int i = 0; i < 26; i++) {
            if(smap[i] != pmap[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int smap[26];
        int pmap[26];
        memset(smap, 0, sizeof(smap));
        memset(pmap, 0, sizeof(pmap));
        int right = 0;
        int n = s.size();
        int m = p.size();
        int cnt = 0;
        vector<int> res;
        if(n < m) {
            return res;
        }
        for(int i = 0; i < m; i++) {
            pmap[p[i] - 'a']++;
        }
        for(int i = 0; i < m; i++) {
            if(pmap[s[i] - 'a']) {
                smap[s[i] - 'a']++;
            }
        }
        if(isSame(smap, pmap)) {
            res.emplace_back(0);
        }
        for(int i = m; i < n; i++) {
            if(pmap[s[i - m] - 'a']) {
                smap[s[i - m] - 'a']--;
            }
            if(pmap[s[i] - 'a']) {
                smap[s[i] - 'a']++;
            }
            if(isSame(smap, pmap)) {
                res.emplace_back(i - m + 1);
            }
        }
        return res;
    }
};

// 2023.06.11
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()){
            return res;
        }
        int count[26] = {0};
        // init p
        for(int i = 0; i < p.size(); i++){
            count[p[i] - 'a']++;
        }
        // init piden
        int pIden = 0;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                pIden++;
            }
        }
        // sliding window
        for(int left = 0, right = 0, sIden = 0; right < s.size(); right++){
            // more right
            if(--count[s[right] - 'a'] == 0){
                sIden++;
            }
            // reduce left
            if(right - left + 1 > p.size() && ++count[s[left++] - 'a'] == 1){
                sIden--;
            }
            // check
            if(sIden == pIden){
                res.push_back(left);
            }
        }
        return res;
    }
};