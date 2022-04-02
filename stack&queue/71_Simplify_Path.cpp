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