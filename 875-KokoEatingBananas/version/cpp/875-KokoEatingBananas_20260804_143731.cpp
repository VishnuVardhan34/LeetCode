// Last updated: 8/4/2026, 2:37:31 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        int left = 1;
5        int right = *max_element(piles.begin(), piles.end());
6
7        while (left < right) {
8            int mid = left + (right - left) / 2;
9
10            long long hours = 0;
11
12            for (int pile : piles) {
13                // Ceiling division
14                hours += (pile + mid - 1) / mid;
15            }
16
17            if (hours <= h) {
18                // This speed works.
19                // Try to find a smaller valid speed.
20                right = mid;
21            } else {
22                // Too slow.
23                left = mid + 1;
24            }
25        }
26
27        return left;
28    }
29};