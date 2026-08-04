// Last updated: 8/4/2026, 12:25:45 PM
int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0) return 0;
    int k=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}