// 2022.04.01
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> files;
        int left = 0;
        while(left < path.size()){
            while(left < path.size() && path[left] == '/'){
                left++;
            }
            int right = left;
            while(right < path.size() && path[right] != '/'){
                right++;
            }
            string file = path.substr(left, right - left);
            left = right;
            if(file == "."){
                continue;
            }
            else if(file == ".."){
                if(!files.empty()){
                    files.pop_back();
                }
            }
            else if(file != ""){
                files.push_back(file);
            }
        }
        string res = "";
        for(auto& f : files){
            res += "/" + f;
        }
        if(res == ""){
            res += "/";
        }
        return res;
    }
};

// 2022.04.08
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> que;
        int left = 0;
        while(left < path.size()){
            while(path[left] == '/' && left < path.size()){
                left++;
            }
            int right = left;
            while(path[right] != '/' && right < path.size()){
                right++;
            }
            string temp = path.substr(left, right - left);
            left = right; // first replace left, or below will not update left
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(!que.empty()){
                    que.pop_back();
                }
            }
            else if(temp != ""){
                que.push_back(temp);
            }
        }
        string res = "";
        for(auto s : que){
            res += "/";
            res += s;
        }
        if(res == ""){
            res += "/";
        }
        return res;
    }
};

// 2022.04.20
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> files;
        int left = 0;
        while(left < path.size()) {
            while(path[left] == '/' && left < path.size()) {
                left++;
            }
            int right = left;
            while(path[right] != '/' && right < path.size()) {
                right++;
            }
            string temp = path.substr(left, right - left);
            left = right;
            if(temp == ".") {
                continue;
            }
            else if(temp == "..") {
                if(!files.empty()) {
                    files.pop_back();
                }
            }
            else if(temp != ""){ // avoiding add "" to files
                files.push_back(temp);
            }
        }
        string res = "";
        for(auto file : files) {
            res += "/";
            res += file;
        }
        if(res == "") {
            res += "/";
        }
        return res;
    }
};