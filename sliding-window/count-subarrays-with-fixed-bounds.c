long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long result = 0;
    int minIndex = -1, maxIndex = -1, leftBound = -1;

    for (int i = 0; i < numsSize; i++) {
        // If the number is out of bounds, reset everything
        if (nums[i] < minK || nums[i] > maxK) {
            leftBound = i;
            minIndex = -1;
            maxIndex = -1;
        }

        // Update minK and maxK indices
        if (nums[i] == minK) minIndex = i;
        if (nums[i] == maxK) maxIndex = i;

        // Only count if both minK and maxK have been found after leftBound
        if (minIndex != -1 && maxIndex != -1) {
            result += (long long)( (minIndex < maxIndex ? minIndex : maxIndex) - leftBound );
        }
    }

    return result;
}
