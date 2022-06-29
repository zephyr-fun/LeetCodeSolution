// 2022.06.29
#include <random>
class Solution {
public:
    unordered_map<string, string> origin2tiny;
    unordered_map<string, string> tiny2origin;
    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string prefix = "https://zephyr_fun.com/tags/";
    int k = 7;
    Solution(): mt(rd()), dis(0, str.size() - 1) {}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(!origin2tiny.count(longUrl)) {
            string temp = "";
            for(int i = 0; i < k; i++) {
                temp += str[dis(mt)];
            }
            temp = prefix + temp;
            if(tiny2origin.count(temp)) {
                continue;
            }
            tiny2origin[temp] = longUrl;
            origin2tiny[longUrl] = temp;
        }
        return origin2tiny[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tiny2origin[shortUrl];
    }

private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dis;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
