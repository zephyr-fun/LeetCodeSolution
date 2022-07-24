// 2022.07.24
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int forward = 0;
        int backward = 0;
        if(start > destination) {
            swap(start, destination);
        }
        for(int i = 0; i < start; i++) {
            backward += distance[i];
        }
        for(int i = destination; i < n; i++) {
            backward += distance[i];
        }
        for(int i = start; i < destination; i++) {
            forward += distance[i];
        }
        return min(forward, backward);
    }
};