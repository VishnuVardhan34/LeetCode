// Last updated: 8/4/2026, 12:23:28 PM
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i] = maximum score difference the current player can achieve
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            dp[i] = INT_MIN;

            // Try taking 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};