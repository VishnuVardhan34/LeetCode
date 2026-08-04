// Last updated: 8/4/2026, 12:22:00 PM
int minOperations(int* nums, int numsSize, int k) {
    long long int sum=0;
    // logic here is the sum % k should be 0 
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    return sum%k;
}