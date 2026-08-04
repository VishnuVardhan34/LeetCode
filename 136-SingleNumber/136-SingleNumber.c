// Last updated: 8/4/2026, 12:25:03 PM
int singleNumber(int* nums, int numsSize) {
    int result=0;
    for(int i=0;i<numsSize;i++){
        result ^= nums[i];
    }
    return result;
}