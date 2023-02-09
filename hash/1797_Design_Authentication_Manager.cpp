// 2023.02.09
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(map.count(tokenId) && currentTime - map[tokenId] < ttl) {
            map[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for(auto& [token, time] : map) {
            if(currentTime - time < ttl) {
                res++;
            }
        }
        return res;
    }
private:
    int ttl;
    unordered_map<string, int> map;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */