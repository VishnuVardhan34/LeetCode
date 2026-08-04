// Last updated: 8/4/2026, 12:25:38 PM
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
