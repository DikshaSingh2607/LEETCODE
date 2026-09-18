class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // first[i] = first occurrence of character i
        // last[i]  = last occurrence of character i
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';

            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int, int>> intervals;

        // Try creating a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // Expand interval if necessary
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character occurs before l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of x
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int lastEnd = -1;

        // Greedily choose non-overlapping intervals
        for (auto [l, r] : intervals) {

            if (l > lastEnd) {

                ans.push_back(s.substr(l, r - l + 1));

                lastEnd = r;
            }
        }

        return ans;
    }
};