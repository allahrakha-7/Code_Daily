class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stk;
        int deletions = 0;

        for (char c : s) {
            if (!stk.empty() && stk.top() == 'b' && c == 'a') 
            {
                deletions++;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return deletions;
    }
};