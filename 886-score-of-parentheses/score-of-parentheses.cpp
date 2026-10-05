class Solution {
public:
 int score;
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for (int i = 0; i<s.size(); i++){
            if(s[i] == '(') st.push(0);
            if(s[i] == ')') {
                int t = st.top(); 
                st.pop();
                score = (t == 0) ? 1 : 2*t;
                st.top() += score;
        }
        }
        return st.top();
    }
};