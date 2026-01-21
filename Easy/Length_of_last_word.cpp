/*Description
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.*/
/* Logic 
1. Take care of empty space at last by decresing the value of i
2. Decrement the value of i until length and increase the count*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;
        
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;
        
        // Count last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
