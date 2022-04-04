// 2022.04.04
class Solution {
private:
    unordered_map<string, map<string, int>> targets;
    vector<string> path;
    bool backtracking(int ticketNum, vector<string>& path){
        if(path.size() == ticketNum + 1){
            return true;
        }
        for(pair<const string, int>& target : targets[path[path.size() - 1]]){
            if(target.second > 0){
                path.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, path)){
                    return true;
                }
                path.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const vector<string>& vec : tickets){
            targets[vec[0]][vec[1]]++;
        }
        path.push_back("JFK");
        backtracking(tickets.size(), path);
        return path;
    }
};