class Solution:
    def findClosestNumber(self, nums: list[int]) -> int:
        closest = nums[0]
        for n in nums:
            if abs(n) < abs(closest):
                closest = n
            elif abs(n) == abs(closest) and n > closest:
                closest = n

        return closest