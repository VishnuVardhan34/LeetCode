// Last updated: 8/6/2026, 12:20:32 PM
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        while (true) {
5            int product = 1;
6            int x = n;
7
8            while (x > 0) {
9                product *= (x % 10);
10                x /= 10;
11            }
12
13            if (product % t == 0)
14                return n;
15
16            n++;
17        }
18    }
19};