class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key-value pairs in the map
        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";
        int i = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                // Extract the key inside the brackets
                string key = "";
                i++;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Replace key with its value
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }

                i++; // Skip the closing bracket
            } else {
                // Copy normal characters
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};