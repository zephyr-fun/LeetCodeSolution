// 2023.05.14
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[barcodes[i]]++;
        }
        sort(barcodes.begin(), barcodes.end(), [&] (int& a, int& b) {
            if(map[a] == map[b]) {
                return a < b;
            }
            return map[a] > map[b];
        });
        vector<int> res(n, 0);
        for(int i = 0, j = 0; i < 2; i++) {
            for(int k = i; k < n; k += 2) {
                res[k] = barcodes[j++];
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int mx = *max_element(barcodes.begin(), barcodes.end());
        int map[mx + 1];
        memset(map, 0, sizeof(map));
        for(int i = 0; i < n; i++) {
            map[barcodes[i]]++;
        }
        sort(barcodes.begin(), barcodes.end(), [&] (int& a, int& b) {
            if(map[a] == map[b]) {
                return a < b;
            }
            return map[a] > map[b];
        });
        vector<int> res(n, 0);
        for(int i = 0, j = 0; i < 2; i++) {
            for(int k = i; k < n; k += 2) {
                res[k] = barcodes[j++];
            }
        }
        return res;
    }
};