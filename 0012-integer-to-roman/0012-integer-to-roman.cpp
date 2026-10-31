class Solution {
public:
    string intToRoman(int num) {

        // Store Roman values
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        // Store corresponding Roman symbols
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string ans = "";

        // Check every Roman value
        for (int i = 0; i < values.size(); i++) {

            // Keep adding the symbol while possible
            while (num >= values[i]) {

                ans += symbols[i];

                num -= values[i];
            }
        }

        return ans;
    }
};