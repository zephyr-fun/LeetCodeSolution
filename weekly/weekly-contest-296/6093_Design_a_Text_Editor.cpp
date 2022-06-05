// 2022.06.05
// TLE
class TextEditor {
public:
    TextEditor() {
        _text = "|";
        _cursorPos = 0;
        _curLen = 1;
    }
    
    void addText(string text) {
        _text = _text.substr(0, _cursorPos) + text + _text.substr(_cursorPos);
        _cursorPos += text.size();
        _curLen += text.size();
        // cout << "add:" << _text << endl;
    }
    
    int deleteText(int k) {
        // cout << "delk:" << k << _curLen << endl;
        if(k >= _cursorPos) {
            int temp = _cursorPos;
            _text = "|" + _text.substr(_cursorPos + 1);
            _cursorPos = 0;
            _curLen -= temp;
            // cout << "del:" << _text << endl;
            return temp;
        } 
        else {
            _text = _text.substr(0, _cursorPos - k) + _text.substr(_cursorPos);
            _cursorPos = _cursorPos - k;
            _curLen -= k;
            // cout << "del:" << _text << endl;
            return k;
        }
        return -1;
    }
    
    string cursorLeft(int k) {
        string left;
        string right;
        if(_curLen == 1) {
            left = "";
        }
        else {
            left = _text.substr(0, _cursorPos);
        }
        if(_cursorPos == _curLen - 1) {
            right = "";
        }
        else {
            right = _text.substr(_cursorPos + 1);
        }
        string temp = left + right;
        // cout << "left:" << temp << endl;
        // cout << "left:" << k << left.size() << endl;
        if(left.size() > k) {
            _cursorPos = _cursorPos - k;
            _text = temp.substr(0, _cursorPos) + "|" + temp.substr(_cursorPos);
            // cout << "left:" << _text << endl;
        }
        else {
            _cursorPos = 0;
            _text = "|" + temp;
            // cout << "left:" << _text << endl;
            return "";
        }
        // cout << "leftre:" << _text.substr(max(_cursorPos - 10, 0), min(_cursorPos - max(_cursorPos - 10, 0), 10)) << endl;
        return _text.substr(max(_cursorPos - 10, 0), min(_cursorPos - max(_cursorPos - 10, 0), 10));
    }
    
    string cursorRight(int k) {
        string left;
        string right;
        if(_curLen == 1) {
            left = "";
        }
        else {
            left = _text.substr(0, _cursorPos);
        }
        if(_cursorPos == _curLen - 1) {
            right = "";
        }
        else {
            right = _text.substr(_cursorPos + 1);
        }
        string temp = left + right;
        if(right.size() > k) {
            _cursorPos = _cursorPos + k;
            _text = temp.substr(0, _cursorPos) + "|" + temp.substr(_cursorPos);
            // cout << "right:" << _text << endl;
        }
        else {
            _cursorPos = _curLen - 1;
            _text = temp + "|";
            // cout << "right:" << _text << endl;
        }
        // cout << "rightre:" << _text.substr(max(_cursorPos - 10, 0), min(_cursorPos - max(_cursorPos - 10, 0), 10)) << endl;
        return _text.substr(max(_cursorPos - 10, 0), min(_cursorPos - max(_cursorPos - 10, 0), 10));
    }
private:
    string _text;
    int _cursorPos;
    int _curLen;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */


// two stack
class TextEditor {
public:
    stack<char> left, right;
    TextEditor() {

    }
    
    void addText(string text) {
        for(auto c : text) {
            left.emplace(c);
        }
    }
    
    int deleteText(int k) {
        int res = min(k, int(left.size()));
        for(int i = 0; i < res; i++) {
            left.pop();
        }
        return res;
    }
    
    string cursorLeft(int k) {
        k = min(k, int(left.size()));
        while(k--) {
            auto c = left.top();
            left.pop();
            right.emplace(c);
        }
        string res;
        for(int i = 0; i < 10 && !left.empty(); i++) {
            res.push_back(left.top());
            left.pop();
        }
        reverse(res.begin(), res.end());
        for(auto c : res) {
            left.emplace(c);
        }
        return res;
    }
    
    string cursorRight(int k) {
        k = min(k, int(right.size()));
        while(k--) {
            auto c = right.top();
            right.pop();
            left.emplace(c);
        }
        string res;
        for(int i = 0; i < 10 && !left.empty(); i++) {
            res.push_back(left.top());
            left.pop();
        }
        reverse(res.begin(), res.end());
        for(auto c : res) {
            left.emplace(c);
        }
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */