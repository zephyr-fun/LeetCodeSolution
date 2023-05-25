// 2022.05.02
class Solution {
public:
    string CDATA1 = "<![CDATA[";
    string CDATA2 = "]]>";
    bool isValid(string code) {
        stack<string> st;
        int size = code.size();
        int index = 0;
        while(index < size) {
            if(index + 8 < size && code.substr(index, 9) == CDATA1) {
                if(index == 0) {
                    return false;
                }
                int supIndex = index + 9;
                bool findC2 = false;
                while(supIndex < size && !findC2) {
                    if(supIndex + 2 < size && code.substr(supIndex, 3) == CDATA2) {
                        findC2 = true;
                    }
                    else {
                        supIndex++;
                    }
                }
                if(!findC2) {
                    return false;
                }
                index = supIndex;
            }
            else if(code[index] == '<') {
                if(index == size - 1) {
                    return false;
                }
                bool isEnd = code[index + 1] == '/';
                int p = isEnd ? index + 2 : index + 1;
                int supIndex = p;
                while(supIndex < size && code[supIndex] != '>') {
                    if(!isupper(code[supIndex])) {
                        return false;
                    }
                    supIndex++;
                }
                if(supIndex == size) {
                    return false;
                }
                int len = supIndex - p;
                if(len < 1 || len > 9) {
                    return false;
                }
                string tagName = code.substr(p, len);
                index = supIndex + 1;
                if(!isEnd) {
                    st.push(tagName);
                }
                else {
                    if(st.empty() || st.top() != tagName) {
                        return false;
                    }
                    st.pop();
                    if(st.empty() && index < size) {
                        return false;
                    }
                }
            }
            else {
                if(index == 0) {
                    return false;
                }
                index++;
            }
        }
        return st.empty();
    }
};

// 2023.05.25
// 栈加仔细分类讨论模拟
class Solution {
public:
    string CDATA1 = "<![CDATA[";
    string CDATA2 = "]]>";
    bool isValid(string code) {
        stack<string> st;
        int size = code.size();
        int idx = 0;
        while(idx < size) {
            if(idx + 8 < size && code.substr(idx, 9) == CDATA1) {
                if(idx == 0) {
                    return false;
                }
                int supIdx = idx + 9;
                bool findCDATA2 = false;
                while(supIdx < size && !findCDATA2) {
                    if(supIdx + 2 < size && code.substr(supIdx, 3) == CDATA2) {
                        findCDATA2 = true;
                    }
                    else {
                        supIdx++;
                    }
                }
                if(!findCDATA2) {
                    return false;
                }
                idx = supIdx;
            }
            else if(code[idx] == '<') {
                if(idx == size - 1) {
                    return false;
                }
                bool isEnd = code[idx + 1] == '/';
                int p = isEnd ? idx + 2 : idx + 1;
                int supIdx = p;
                while(supIdx < size && code[supIdx] != '>') {
                    if(!isupper(code[supIdx])) {
                        return false;
                    }
                    supIdx++;
                }
                if(supIdx == size) {
                    return false;
                }
                int len = supIdx - p;
                if(len < 1 || len > 9) {
                    return false;
                }
                string tagName = code.substr(p, len);
                idx = supIdx + 1;
                if(!isEnd) {
                    st.push(tagName);
                }
                else {
                    if(st.empty() || st.top() != tagName) {
                        return false;
                    }
                    st.pop();
                    if(st.empty() && idx < size) {
                        return false;
                    }
                }
            }
            else {
                if(idx == 0) {
                    return false;
                }
                idx++;
            }
        }
        return st.empty();
    }
};