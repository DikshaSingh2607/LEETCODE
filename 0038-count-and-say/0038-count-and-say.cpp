
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            int j = 0;

            while (j < s.length()) {
                int count = 1;

                while (j + 1 < s.length() && s[j] == s[j + 1]) {
                    count++;
                    j++;
                }

                temp += to_string(count) + s[j];
                j++;
            }

            s = temp;
        }

        return s;
    }
};
