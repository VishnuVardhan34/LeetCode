# Last updated: 8/4/2026, 12:23:55 PM
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        
        # last two chosen numbers
        a, b = -1, -1  
        res = 0
        
        for s, e in intervals:
            hasA = a >= s and a <= e
            hasB = b >= s and b <= e
            
            if hasA and hasB:
                continue
            elif hasB:
                # Only one number is valid, add one more (e)
                res += 1
                a, b = b, e
            else:
                # Need to add two numbers (e-1, e)
                res += 2
                a, b = e - 1, e
        
        return res
