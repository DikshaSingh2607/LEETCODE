class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        // Take the first string as reference
        for (int i = 0; i < strs[0].size(); i++) {

            char ch = strs[0][i];

            // Compare with every other string
            for (int j = 1; j < strs.size(); j++) {

                // Check if index exists and character matches
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            // If all strings match, add character
            ans += ch;
        }

        return ans;
    }
};