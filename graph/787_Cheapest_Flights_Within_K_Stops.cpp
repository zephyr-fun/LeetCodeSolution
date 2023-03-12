// 2023.03.12
// bellman ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k = k + 1;
        int dist[n];
        int backup[n]; // avoid multi update
        function<void()> bf = [&] () {
            memset(dist, 0x3f, sizeof(dist));
            dist[src] = 0; // src set as the start point
            for(int i = 0; i < k; i++) {
                memcpy(backup, dist, sizeof(dist)); // copy the last state
                for(auto& flight : flights) {
                    dist[flight[1]] = min(dist[flight[1]], backup[flight[0]] + flight[2]); // update
                }
            }
        };
        bf();
        return dist[dst] >= 0x3f3f3f3f / 2 ? -1 : dist[dst]; 
    }
};