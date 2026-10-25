class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int closeCount = 0;
        for(int i = 0; i<s.size(); i++){
            if (s[i] == '(') openCount +=  1;
            else if(s[i] == ')' && openCount > 0) openCount-= 1;
            else closeCount += 1;
        }

        return openCount + closeCount;
    }
};