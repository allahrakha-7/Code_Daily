class Solution {
public:
    string decodeString(string s) {
        string stack;

        for (char c : s) {

            if (c != ']') {

                stack.push_back(c);
                
            } else {

                string subStr = "";

                while (!stack.empty() && stack.back() != '[') {

                    subStr = stack.back() + subStr;

                    stack.pop_back();
                }
                stack.pop_back();

                string k = "";

                while (!stack.empty() && isdigit(stack.back())) {

                    k = stack.back() + k;

                    stack.pop_back();
                }
                int repeat = stoi(k);

                while (repeat--) {
                    
                    stack += subStr;
                }
            }
        }
        return stack;
    }
};