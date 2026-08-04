# Last updated: 8/4/2026, 12:24:26 PM
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n>-1 and bin(n).count('1')==1