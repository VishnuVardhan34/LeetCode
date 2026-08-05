// Last updated: 8/6/2026, 12:46:29 AM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, int> last;
5        int l = 0, ans = 0;
6
7        for (int r = 0; r < s.size(); r++) {
8            if (last.count(s[r]) && last[s[r]] >= l)
9                l = last[s[r]] + 1;
10
11            last[s[r]] = r;
12            ans = max(ans, r - l + 1);
13        }
14
15        return ans;
16    }
17};