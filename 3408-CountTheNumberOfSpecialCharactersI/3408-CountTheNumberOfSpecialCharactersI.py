# Last updated: 8/4/2026, 12:22:28 PM
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        
        lower = set()
        upper = set()

        for ch in word:
            if ch.islower():
                lower.add(ch)
            else:
                upper.add(ch.lower())

        return len(lower & upper)