class Solution {
public:
    bool isValid(string s) {
        
        stack<char> validParentheses;

        for (char c : s) {

            if (c == '(' || c == '{' || c == '[') {

                validParentheses.push(c);
                
            } else if (c == ')' || c == '}' || c == ']') {

                if (validParentheses.empty()) {

                    return false;
                }

                char top = validParentheses.top();
                validParentheses.pop();
                
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return validParentheses.empty();
    }
};