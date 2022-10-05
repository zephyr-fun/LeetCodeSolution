// 2022.10.05
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for(auto cp : cpdomains) {
            int n = cp.size();
            int idx = 0;
            while(idx < n && cp[idx] != ' ') {
                idx++;
            }
            int num = stoi(cp.substr(0, idx));
            string domain = cp.substr(idx + 1);
            while(domain.size() > 0) {
                map[domain] += num;
                int dot = 0;
                while(dot < domain.size() && domain[dot] != '.') {
                    dot++;
                }
                if(dot < domain.size()) {
                    domain = domain.substr(dot + 1);
                }
                else {
                    break;
                }
            }
        }
        vector<string> res;
        for(auto& [k, v] : map) {
            string temp = to_string(v);
            temp += ' ';
            temp += k;
            res.emplace_back(temp);
        }
        return res;
    }
};