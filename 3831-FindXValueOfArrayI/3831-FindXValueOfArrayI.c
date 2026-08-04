// Last updated: 8/4/2026, 12:22:08 PM
long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* result = (long long*)calloc(k, sizeof(long long));
    long long* dp = (long long*)calloc(k, sizeof(long long));
    long long* next = (long long*)calloc(k, sizeof(long long));

    for (int i = 0; i < numsSize; ++i) {
        memset(next, 0, k * sizeof(long long));

        int curr_mod = nums[i] % k;
        next[curr_mod] += 1; // subarray with just nums[i]

        for (int j = 0; j < k; ++j) {
            if (dp[j] > 0) {
                int new_mod = (1LL * j * nums[i]) % k;
                next[new_mod] += dp[j];
            }
        }

        for (int j = 0; j < k; ++j) {
            result[j] += next[j];
            dp[j] = next[j];  // update dp for next iteration
        }
    }

    free(dp);
    free(next);
    *returnSize = k;
    return result;
}
