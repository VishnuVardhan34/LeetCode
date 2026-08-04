// Last updated: 8/4/2026, 5:19:27 PM
1class Solution {
2public:
3    int maxArea(vector<int>& heights) {
4        int area=0,l=0,r=heights.size()-1,maxArea=0;
5        while(l<r) {
6            area = min(heights[l], heights[r]) * (r-l);
7            maxArea = max(maxArea, area);
8            heights[l] < heights[r] ? l++ : r--;
9        }
10        return maxArea;
11    }
12};