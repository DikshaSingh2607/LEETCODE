class Solution {
public:
    string s;
    int i = 0;

    set<string> parseUnion() {
        set<string> result = parseConcat();

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> next = parseConcat();

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> parseConcat() {
        set<string> result = {""};

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> next;

            if (s[i] == '{') {
                i++;
                next = parseUnion();
                i++; // Skip closing brace
            } else {
                next.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (const string& a : result) {
                for (const string& b : next) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result = parseUnion();

        return vector<string>(result.begin(), result.end());
    }
};