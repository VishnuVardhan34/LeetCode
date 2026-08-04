// Last updated: 8/4/2026, 5:17:02 PM
1class Solution {
2public:
3    int maxArea(vector<int>& heights) {
4        int area=0,l=0,r=heights.size()-1,maxArea=0;
5        while(l<r) {
6            area = min(heights[l], heights[r]) * (r-l);
7            maxArea = max(maxArea, area);
8            if(heights[l] < heights[r]) {
9                l++;
10            } else {
11                r--;
12            }
13        }
14        return maxArea;
15    }
16};