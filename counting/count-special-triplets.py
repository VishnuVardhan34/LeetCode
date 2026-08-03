class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        if n < 3:
            return 0

        maxv = max(nums)
        size = maxv * 2 + 1

        left = [0] * size
        right = [0] * size

        for v in nums:
            right[v] += 1

        ans = 0
        for v in nums:
            right[v] -= 1  # treat v as nums[j]
            target = v * 2
            if target < size:
                ans = (ans + left[target] * right[target]) % mod
            left[v] += 1

        return ans % mod
