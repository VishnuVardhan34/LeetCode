// Last updated: 8/4/2026, 5:29:01 PM
1class Solution {
2public:
3    int trap(vector<int>& heights) {
4        if (heights.empty()) return 0;
5        int l=0,r=heights.size()-1;
6        int lMax = heights[l], rMax = heights[r], ans=0;
7        while(l<r) {
8            if (lMax < rMax) {
9                l++;
10                lMax = max(lMax, heights[l]);
11                ans += lMax  - heights[l];
12            } else {
13                r--;
14                rMax = max(rMax, heights[r]);
15                ans += rMax - heights[r];
16            }
17        }
18        return ans;
19    }
20};
21