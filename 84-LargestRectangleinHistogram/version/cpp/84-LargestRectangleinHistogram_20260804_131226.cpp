// Last updated: 8/4/2026, 1:12:26 PM
1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        int n = heights.size();
5        int maxArea = 0;
6        stack<int> stack;
7        for (int i=0;i<=n;i++) {
8            while(!stack.empty() && (i == n || heights[stack.top()] >= heights[i])){
9                int height = heights[stack.top()];
10                stack.pop();
11                int width = stack.empty() ? i : i - stack.top() - 1;
12                maxArea = max(maxArea, height * width);
13            }
14            stack.push(i);
15        }
16        return maxArea;
17    }
18};