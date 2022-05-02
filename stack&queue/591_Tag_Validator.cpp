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