// 2022.07.07
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int n = 1e5 + 7;
vector<vector<int>> son(n, vector<int>(26, 0));
int idx = 0;
vector<int> cnt(n, 0);

void insert(string& s) {
    int p = 0;
    for(int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string& s) {
    int p = 0;
    for(int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        string opt;
        cin >> opt;
        string temp;
        cin >> temp;
        if(opt == "I") {
            insert(temp);
        }
        else {
            cout << query(temp) << endl;
        }
    }
    return 0;
}

// dynamic new
class Trie {
private:
    bool is_string = false;
    Trie* next[26] = {nullptr};
public:
    Trie() {

    }

    void insert(string& word) {
        Trie* root = this;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] == nullptr) {
                root->next[u] = new Trie();
            }
            root = root->next[u];
        }
        root->is_string = true;
    }

    bool startsWith(string& word) {
        Trie* root = this;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] != nullptr) {
                root = root->next[u];
                if(root->is_string) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }

    bool query(string& word) {
        Trie* root = this;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] == nullptr) {
                return false;
            }
            root = root->next[u];
        }
        return root->is_string;
    }
};

class StreamChecker {
private:
    Trie* root;
    string word;
public:
    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(auto word:words){
            reverse(word.begin(),word.end());
            root->insert(word);
        }
    }
    
    bool query(char letter) {
        Trie* note=root;
        word.insert(word.begin(),letter);
        return note->startsWith(word);
    }
};