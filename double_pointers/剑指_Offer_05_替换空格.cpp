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

// double pointers
class Solution {
public:
    string replaceSpace(string s) {
        int spaceCount = 0;
        int oldSize = s.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                spaceCount++;
            }
        }
        int newSize = oldSize + (2 * spaceCount);
        s.resize(newSize);
        for(int oldIndex = oldSize - 1, newIndex = newSize - 1; oldIndex < newIndex; oldIndex--, newIndex--){
            if(s[oldIndex] != ' '){
                s[newIndex] = s[oldIndex];
            }
            else{
                s[newIndex] = '0';
                s[newIndex - 1] = '2';
                s[newIndex - 2] = '%';
                newIndex -= 2;
            }
        }
        return s;
    }
};