// 2022.06.13
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        unordered_map<string, int> group;
        for(auto& idea : ideas) {
            group[idea.substr(1)] |= 1 << (idea[0] - 'a');
        }
        int cnt[26][26]; // refers to total nums of group with i and without j
        memset(cnt, 0, sizeof(cnt)); // matters when using []array
        for(auto& [_, mask] : group) {
            for(int i = 0; i < 26; i++) {
                cout << 'a' + i << endl;
                if((mask >> i & 1) == 0) {
                    for(int j = 0; j < 26; j++) {
                        cout << "if" << 'a' + j << endl;
                        if(mask >> j & 1) {
                            cnt[i][j]++;
                        }
                    }
                }
                else {
                    for(int j = 0; j < 26; j++) {
                        cout << "else" << 'a' + j << endl;
                        if((mask >> j & 1) == 0) {
                            res += cnt[i][j];
                        }
                    }
                }
            }
        }
        return res * 2;
    }
};