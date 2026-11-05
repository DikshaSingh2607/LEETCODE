
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        backtrack(0, digits, temp, ans, mp);

        return ans;
    }

    void backtrack(int index, string &digits, string &temp,
                   vector<string> &ans, vector<string> &mp) {

        // Base case
        if (index == digits.length()) {
            ans.push_back(temp);
            return;
        }

        // Get letters for current digit
        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            temp.push_back(ch);

            backtrack(index + 1, digits, temp, ans, mp);

            temp.pop_back();  // Backtracking
        }
    }
};
