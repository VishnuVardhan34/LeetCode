class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n>-1 and bin(n).count('1')==1