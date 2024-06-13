class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        int j = 0;

        for (int i = 0; i < t_len; i++)
        {
            if (s[j] == t[i])
            {
                j++;
            }
            if (j == s_len)
            {
                return true;
            }
        }
        return (j == s_len);
    }
};