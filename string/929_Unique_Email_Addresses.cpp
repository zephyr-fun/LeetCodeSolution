// 2022.06.04
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(int i = 0; i < emails.size(); i++) {
            string temp = emails[i];
            string res = "";
            for(int j = 0; j < temp.size(); j++) { // for(int j = 0; "i" < temp.size(); j++)?????
                if(temp[j] == '+') {
                    while(temp[j + 1] != '@') {
                        j++;
                    }
                }
                else if(temp[j] == '.') {
                    continue;
                }
                else if(temp[j] == '@') {
                    while(j < temp.size()) {
                        res += temp[j];
                        j++;
                    }
                    break;
                }
                else {
                    res += temp[j];
                }
            }
            // cout << temp << "_" << res << "_" << set.size() << endl;
            set.insert(res);
        }
        return set.size();
    }
};

// api
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(auto email : emails) {
            int pos = email.find('@');
            string local_name = email.substr(0, pos);
            string simply = "";
            for(auto c : local_name) {
                if(c == '.') {
                    continue;
                }
                else if(c == '+') {
                    break;
                }
                else {
                    simply += c;
                }
            }
            set.insert(simply + email.substr(pos));
        }
        return set.size();
    }
};