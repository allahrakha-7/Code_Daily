class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(result, "", digits, mapping, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string combination, string digits, vector<string>& mapping, int index) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }

        string letters = mapping[digits[index] - '2'];

        for (int i = 0; i < letters.length(); i++) {
            backtrack(result, combination + letters[i], digits, mapping, index + 1);
        }
    }
};