class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        total_time=0
        n=len(colors)

        for i in range(1,n):
            # if two consec have the same color
            if colors[i] == colors[i-1]:
                # Remove the one with smaller reach time
                total_time += min(neededTime[i], neededTime[i-1])
                neededTime[i] = max(neededTime[i], neededTime[i-1])

        return total_time