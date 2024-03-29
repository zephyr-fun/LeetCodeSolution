// 2022.07.22
class Solution {
public:
    int n;
    vector<vector<int>> children;
    long long maxVal = -0x3f3f3f3f;
    int cnt = 0;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children.resize(n);
        for(int i = 1; i < n; i++) {
            children[parents[i]].emplace_back(i);
        }
        dfs(0);
        return cnt;
    }
    int dfs(int node) {
        int tot = n - 1;
        vector<int> sub;
        for(int i = 0; i < children[node].size(); i++) {
            sub.emplace_back(dfs(children[node][i]));
            tot -= sub.back();
        }
        long long sum = 1;
        if(tot != 0) {
            sum = tot;
        }
        for(int i = 0; i < sub.size(); i++) {
            sum *= sub[i];
        }
        if(sum > maxVal) {
            maxVal = sum;
            cnt = 1;
        }
        else if(sum == maxVal) {
            cnt++;
        }
        return n - tot;
    }
};

// 2022.07.27
class Solution {
public:
    int n;
    long long maxVal = -0x3f3f3f3f;
    int res = 0;
    vector<vector<int>> children;
    int dfs(int u) {
        int tot = n - 1;
        vector<int> temp;
        for(int i = 0; i < children[u].size(); i++) {
            temp.emplace_back(dfs(children[u][i]));
            tot -= temp.back();
        }
        long long sum = 1;
        if(tot != 0) {
            sum *= tot;
        }
        for(int i = 0; i < temp.size(); i++) {
            sum *= temp[i];
        }
        if(sum > maxVal) {
            maxVal = sum;
            res = 1;
        }
        else if(sum == maxVal) {
            res++;
        }
        return n - tot;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children.resize(n);
        for(int i = 1; i < parents.size(); i++) {
            children[parents[i]].emplace_back(i);
        }
        dfs(0);
        return res;
    }
};