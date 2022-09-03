// 2022.06.19
#include<sstream>
class Solution {
public:
    int MAXN = 107;
    int inDeg[107];
    bool Topo(int n, vector<vector<int>>& graph) {
        queue<int> node;
        for(int i = 0; i < n; i++) {
            if(inDeg[i] == 0) {
                node.push(i);
            }
        }
        int num = 0;
        while(!node.empty()) {
            int u = node.front();
            node.pop();
            num++;
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                inDeg[v]--;
                if(inDeg[v] == 0) {
                    node.push(v);
                }
            }
        }
        cout << n << num;
        return n == num - 1;
    }
    
    bool hasCycle(string graph) {
        int len = graph.size();
        set<int> nodeCnt;
        // memset(graph, 0, sizeof(graph));
        vector<vector<int>> edge(MAXN, vector<int>());
        memset(inDeg, 0, sizeof(inDeg));
        for(int i = 0; i < len; i++) {
            if(graph[i] == ',') {
                graph[i] = ' ';
            }
        }
        istringstream out(graph);
        string str;
        while(out >> str) {
            int u = stoi(str.substr(0, str.find('-')));
            int v = stoi(str.substr(str.find('>') + 1));
            // cout << u << v << endl;
            edge[u].push_back(v);
            inDeg[v]++;
            nodeCnt.insert(u);
            nodeCnt.insert(v);
        }
        int n = nodeCnt.size();
        if(!Topo(n, edge)) {
            return true;
        }
        return false;
    }
};