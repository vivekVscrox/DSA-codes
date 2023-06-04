/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxlen = 0;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if(ch=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};