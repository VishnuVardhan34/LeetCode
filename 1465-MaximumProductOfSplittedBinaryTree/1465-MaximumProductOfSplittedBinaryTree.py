# Last updated: 8/4/2026, 12:23:34 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        max_prod = 0

        def totalSum(node):
            if not node:
                return 0
            return node.val + totalSum(node.left) + totalSum(node.right)

        total = totalSum(root)

        def dfs(node):
            nonlocal max_prod
            if not node:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)

            sub_sum = node.val + left + right
            max_prod = max(max_prod, sub_sum * (total - sub_sum))
            return sub_sum

        dfs(root)
        return max_prod % MOD
