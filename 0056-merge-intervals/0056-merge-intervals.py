
class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort(key=lambda x: x[0])

        result = []
        current = intervals[0]

        for interval in intervals[1:]:
            # Does the next interval overlap with current?
            if interval[0] <= current[1]:
                # Extend the current interval's end
                current[1] = max(current[1], interval[1])
            else:
                # Save current and start a new interval
                result.append(current)
                current = interval

        # Save the final interval
        result.append(current)

        return result
