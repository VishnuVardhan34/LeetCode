// Last updated: 8/4/2026, 2:50:20 PM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int l=0,r=s.size()-1;
5        while(l<r) {
6            while(l<r && !isalnum(s[l])) l++;
7            while(l<r && !isalnum(s[r])) r--;
8            if(tolower(s[l]) != tolower(s[r])) return false;
9            l++;
10            r--;
11        }
12        return true;
13    }
14};