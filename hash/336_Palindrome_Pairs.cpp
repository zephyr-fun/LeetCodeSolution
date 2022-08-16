// 2022.08.16
// yxc version
typedef unsigned long long ULL;

const int N = 310, P = 131;

ULL p[N];

class Solution {
public:
    vector<vector<ULL>> h1, h2;

    ULL get(vector<ULL>& h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        p[0] = 1;
        for (int i = 1; i < N; i ++ ) p[i] = p[i - 1] * P;

        for (int i = 0; i < words.size(); i ++ ) {
            int n = words[i].size();
            vector<ULL> a(1), b(1);
            for (int j = 1; j <= n; j ++ ) a.push_back(a.back() * P + words[i][j - 1]);
            for (int j = n; j; j -- ) b.push_back(b.back() * P + words[i][j - 1]);
            h1.push_back(a);
            h2.push_back(b);
        }

        unordered_map<ULL, int> hash;
        for (int i = 0; i < words.size(); i ++ )
            hash[get(h2[i], 1, words[i].size())] = i;

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++ ) {
            int n = words[i].size();
            for (int j = 0; j <= n; j ++ ) {
                auto left = get(h1[i], 1, j), right = get(h1[i], j + 1, n);
                if (right == get(h2[i], 1, n - j) && hash.count(left) && hash[left] != i) res.push_back({i, hash[left]});
                if (left == get(h2[i], n - j + 1, n) && hash.count(right) && hash[right] != i && words[i].size() != words[hash[right]].size())
                    res.push_back({hash[right], i});
            }
        }
        return res;
    }
};