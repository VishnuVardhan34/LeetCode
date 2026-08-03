from collections import Counter

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        ans = []
        
        for i in range(n - k + 1):
            window = nums[i:i+k]
            freq = Counter(window)

            sorted_items = sorted(freq.items(), key=lambda p: (p[1], p[0]), reverse=True)

            top_x = sorted_items[:x]

            total = sum(num * freq[num] for num, _ in top_x)
            ans.append(total)
        
        return ans
