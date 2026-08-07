// Last updated: 8/8/2026, 1:35:24 AM
1#include <iostream>
2#include <string>
3#include <vector>
4#include <algorithm>
5
6using namespace std;
7
8class Solution {
9private:
10    bool isInvalid(long long n) {
11        for (int i = 2; i < 10; i++) {
12            while (n % i == 0) {
13                n /= i;
14            }
15        }
16        return n != 1;
17    }
18
19    int minDigitsNeeded(long long t) {
20        if (t <= 1) {
21            return 0;
22        }
23
24        int count = 0;
25
26        for (int d = 9; d >= 2; d--) {
27            while (t % d == 0) {
28                count++;
29                t /= d;
30            }
31        }
32
33        return count;
34    }
35
36    string getMore(long long t) {
37        string sol = "";
38
39        while (t != 1) {
40            int curr = 9;
41
42            while (curr > 1 && (t % curr != 0)) {
43                curr--;
44            }
45
46            sol.push_back(char(curr + '0'));
47            t /= curr;
48        }
49
50        reverse(sol.begin(), sol.end());
51        return sol;
52    }
53
54    long long reduceT(long long t, int d) {
55        for (int f = 9; f >= 2; f--) {
56            while (d % f == 0 && t % f == 0) {
57                t /= f;
58                d /= f;
59            }
60        }
61
62        return t;
63    }
64
65public:
66    string smallestNumber(string num, long long t) {
67        int n = num.size();
68
69        if (isInvalid(t)) {
70            return "-1";
71        }
72
73        int zeroIdx = -1;
74
75        for (int i = 0; i < n; i++) {
76            if (num[i] == '0') {
77                zeroIdx = i;
78                break;
79            }
80        }
81
82        if (zeroIdx == -1) {
83            long long tempT = t;
84
85            for (char c : num) {
86                tempT = reduceT(tempT, c - '0');
87            }
88
89            if (tempT == 1) {
90                return num;
91            }
92        }
93
94        int maxPrefix = (zeroIdx == -1) ? n : zeroIdx + 1;
95
96        vector<long long> prefixT(n + 1, t);
97
98        for (int i = 0; i < maxPrefix - 1; i++) {
99            prefixT[i + 1] = reduceT(prefixT[i], num[i] - '0');
100        }
101
102        for (int i = maxPrefix - 1; i >= 0; i--) {
103            int remainingLen = n - 1 - i;
104            int startDigit = max(1, (num[i] - '0') + 1);
105
106            for (int d = startDigit; d <= 9; d++) {
107                long long remT = reduceT(prefixT[i], d);
108
109                if (minDigitsNeeded(remT) <= remainingLen) {
110                    string sol = num.substr(0, i);
111                    sol.push_back(char(d + '0'));
112
113                    string suffix = getMore(remT);
114
115                    // FIX: Append all '1's efficiently at once to avoid O(N^2) memory and time overhead
116                    if (suffix.size() < remainingLen) {
117                        sol.append(remainingLen - suffix.size(), '1');
118                    }
119                    
120                    sol += suffix;
121                    return sol;
122                }
123            }
124        }
125
126        int reqLen = max(n + 1, minDigitsNeeded(t));
127        string suffix = getMore(t);
128        string sol = "";
129        
130        // FIX: Prepend '1's efficiently here as well
131        if (suffix.size() < reqLen) {
132            sol.append(reqLen - suffix.size(), '1');
133        }
134        
135        sol += suffix;
136        return sol;
137    }
138};