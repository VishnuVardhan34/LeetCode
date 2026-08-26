class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                if (ones == k) {
                    string cur = s.substr(i, j - i + 1);

                    // First valid answer, or shorter answer
                    // or same length but lexicographically smaller
                    if (ans.empty() ||
                        cur.length() < ans.length() ||
                        (cur.length() == ans.length() && cur < ans)) {
                        ans = cur;
                    }

                    // Extending further cannot give a shorter
                    // substring starting at i.
                    break;
                }
            }
        }

        return ans;
    }
};