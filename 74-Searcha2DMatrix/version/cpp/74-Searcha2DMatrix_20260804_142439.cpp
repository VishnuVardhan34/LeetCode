// Last updated: 8/4/2026, 2:24:39 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int rows = matrix.size();
5        int cols = matrix[0].size();
6
7        int top = 0;
8        int bottom = rows - 1;
9
10        while (top <= bottom) {
11            int mid = top + (bottom - top) / 2;
12
13            if (target < matrix[mid][0]) {
14                bottom = mid - 1;
15            }
16            else if (target > matrix[mid][cols - 1]) {
17                top = mid + 1;
18            }
19            else {
20                // Target must be in this row
21                int left = 0;
22                int right = cols - 1;
23
24                while (left <= right) {
25                    int m = left + (right - left) / 2;
26
27                    if (matrix[mid][m] == target)
28                        return true;
29                    else if (matrix[mid][m] < target)
30                        left = m + 1;
31                    else
32                        right = m - 1;
33                }
34
35                return false;
36            }
37        }
38
39        return false;
40    }
41};