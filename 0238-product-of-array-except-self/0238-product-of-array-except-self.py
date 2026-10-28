class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        answer = [1] * n # initilizing the size of array

        # Calculate the prefix(s) product
        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]
        
        # Calcualte the suffix(s) product
        suffix = 1
        for i in range(n -1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer
