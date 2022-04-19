// 2022.03.31
// resize + double pointers
class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        int count = 0;
        for(int i = 0; i < oldSize; i++){
            if(s[i] == ' '){
                count++;
            }
        }
        int newSize = oldSize + 2 * count;
        s.resize(newSize); // resize(new length)
        for(int front = oldSize - 1, back = newSize - 1; front < back; front--, back--){
            if(s[front] != ' '){
                s[back] = s[front];
            }
            else{
                s[back] = '0';
                s[back - 1] = '2';
                s[back - 2] = '%';
                back -= 2;
            }
        }
        return s;
    }
};

// 2022.04.19
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                count++;
            }
        }
        int oldSize = s.size();
        int newSize = oldSize + 2 * count;
        s.resize(newSize);
        int oldIndex = oldSize - 1;
        int newIndex = newSize - 1;
        while(oldIndex < newIndex && oldIndex >= 0) {
            if(s[oldIndex] == ' ') {
                s[newIndex] = '0';
                s[newIndex - 1] = '2';
                s[newIndex - 2] = '%';
                newIndex -= 3;
                oldIndex -= 1;
            }
            else {
                s[newIndex] = s[oldIndex];
                newIndex -= 1;
                oldIndex -= 1;
            }
        }
        return s;
    }
};