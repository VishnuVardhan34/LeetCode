/* Challenge description 
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/
/* Logic:
   1. Tale care if needle length is greater than the haystack length, return -1 
   2. Run the loop for h-n times and i used the substr() to check the substring needle in haystack*/

   class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n > h) return -1;

        for (int i=0; i <= h-n; i++){
            if(haystack.substr(i, n) == needle)
            return i;
        }

        return -1;
    }
};