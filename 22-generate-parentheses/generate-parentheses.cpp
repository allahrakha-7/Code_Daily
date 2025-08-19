class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        stack<string> st;
        st.push("(");


        while (!st.empty()) {

            string current = st.top();

            st.pop();

            int open = 0;
            int close = 0;

            for (char c : current) {

                if (c == '(') {

                    open++;

                } else {

                    close++;
                }
            }
            
            if (open == n && close == n) {

                result.push_back(current);

                continue;
            }
            
            if (open < n) {

                st.push(current + "(");

            }

            if (close < open) {

                st.push(current + ")");

            }
        }
        return result;
    }
};