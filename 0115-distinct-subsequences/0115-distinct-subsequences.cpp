class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(m + 1, 0)
        );

        // Empty t can always be formed
        dp[0][0] = 1;

        // Any non-empty s can form empty t in exactly 1 way
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Don't take s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Take s[i-1] if characters match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }

                // We only care about values up to INT_MAX
                if (dp[i][j] > INT_MAX) {
                    dp[i][j] = INT_MAX;
                }
            }
        }

        return (int)dp[n][m];
    }
};