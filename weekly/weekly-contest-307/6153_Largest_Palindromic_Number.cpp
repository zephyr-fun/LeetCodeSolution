// 2022.08.29 sorted
class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int, int> map;
        unordered_map<int, int> nmap;
        for(auto c : num) {
            map[c - '0']++;
        }
        string res = "";
        int maxVal = -1;
        for(auto [k, v] : map) {
            // cout << k << v << endl;
            if((v & 1) == 1) {
                maxVal = max(maxVal, k);
                if(v - 1 > 0) {
                    nmap[k] = v - 1;
                }
            }
            else {
                nmap[k] = v;
            }
        }
        // cout << "!!" << endl;
        res = maxVal == -1 ? "" : to_string(maxVal);
        vector<pair<int, int>> temp(nmap.begin(), nmap.end());
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        // cout << "!!" << endl;
        int n = temp.size();
        for(int i = n - 1; i >= 0; i--) {
            int k = temp[i].first;
            int v = temp[i].second;
            // cout << k << v << endl;
            string ss = "";
            for(int j = 0; j < v / 2; j++) {
                ss += '0' + k;
            }
            res = ss + res + ss;
        }
        // cout << res;
        int i = 0;
        while(res[i] == '0') {
            i++;
        }
        if(i > 0) {
            res = res.substr(i, res.size() - 2 * i);   
        }
        return res == "" ? "0" : res;
    }
};