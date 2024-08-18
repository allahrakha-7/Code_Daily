class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry != 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int curSum = digit1 + digit2 + carry;

            carry = curSum / 10;
            sum += to_string(curSum % 10);

            i--;
            j--;
        }
        reverse(sum.begin(), sum.end());
        return sum; 
    }
};