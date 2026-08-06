// Last updated: 8/6/2026, 12:41:26 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        unordered_map<char, int> freq;
5
6        int l = 0;
7        int maxFreq = 0;
8        int ans = 0;
9
10        for (int r = 0; r < s.size(); r++) {
11            freq[s[r]]++;
12            maxFreq = max(maxFreq, freq[s[r]]);
13
14            while ((r - l + 1) - maxFreq > k) {
15                freq[s[l]]--;
16                l++;
17            }
18
19            ans = max(ans, r - l + 1);
20        }
21
22        return ans;
23    }
24};