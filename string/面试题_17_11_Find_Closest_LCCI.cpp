// 2022.05.27
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> map;
        for(int i = 0; i < words.size(); i++) {
            map[words[i]].push_back(i);
        }
        vector<int> temp1 = map[word1];
        vector<int> temp2 = map[word2];
        int res = 0x3f3f3f3f;
        int temp1Index = 0;
        int temp2Index = 0;
        while(temp1Index < temp1.size() && temp2Index < temp2.size()) {
            res = min(res, abs(temp1[temp1Index] - temp2[temp2Index]));
            if(temp1[temp1Index] > temp2[temp2Index]) {
                temp2Index++;
            }
            else {
                temp1Index++;
            }
        }
        return res;
    }
};

// other simulate
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int res = 0x3f3f3f3f;
        int index1 = -1;
        int index2 = -1;
        for(int i = 0; i < words.size(); i++) {
            string cur = words[i];
            if(cur == word1) {
                index1 = i;
            }
            else if(cur == word2) {
                index2 = i;
            }
            if(index1 != -1 && index2 != -1) {
                res = min(res, abs(index1 - index2));
            }
        }
        return res;
    }
};