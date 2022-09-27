// 2022.09.01
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> map(62);
        for(int i = 0; i < 62; i++) {
            map[i].first = i;
            map[i].second = 0;
        }
        for(auto c : s) {
            if(c >= 'a' && c <= 'z') {
                map[c - 'a'].second++;
            }
            else if(c >= 'A' && c <= 'Z'){
                map[c - 'A' + 26].second++;
            }
            else {
                map[c - '0' + 52].second++;
            }
        }
        sort(map.begin(), map.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        string res = "";
        for(auto& [k, v] : map) {
            if(v == 0) {
                break;
            }
            int temp = v;
            while(temp > 0) {
                if(k >= 0 && k < 26) {
                    res += 'a' + k;
                }
                else if(k >= 26 && k < 52){
                    res += 'A' + k - 26;
                }
                else {
                    res += '0' + k - 52;
                }
                temp--;
            }
        }
        return res;
    }
};

// 2022.09.27
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> map;
        for(auto& c : s) {
            map[c]++;
        }
        vector<pair<char, int>> temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [](pair<char, int>& a, pair<char, int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        for(auto& t : temp) {
            for(int i = 0; i < t.second; i++) {
                res += t.first;
            }
        }
        return res;
    }
};