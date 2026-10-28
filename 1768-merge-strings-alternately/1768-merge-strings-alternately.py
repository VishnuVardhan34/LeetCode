class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = ""
        i=0
        while i < len(word1) and i < len(word2):
            merged += word1[i]
            merged += word2[i]
            i += 1
        merged += word1[i:]
        merged += word2[i:]

        return merged