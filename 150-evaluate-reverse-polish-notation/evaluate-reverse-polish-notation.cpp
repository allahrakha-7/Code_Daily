class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a + b);
            }
            else if (token == "-") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a - b);
            }
            else if (token == "*") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a * b);
            }
            else if (token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a / b);
            }
            else {
                // It's a number
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};