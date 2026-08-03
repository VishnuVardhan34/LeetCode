
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    
    // Fill from the end
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        // No carry: copy the result[1..] into a new array of correct size
        int* trimmedResult = (int*)malloc(digitsSize * sizeof(int));
        for (int i = 0; i < digitsSize; i++) {
            trimmedResult[i] = result[i + 1];
        }
        *returnSize = digitsSize;
        free(result); // free original allocation
        return trimmedResult;
    }
}
