// Last updated: 8/4/2026, 12:24:50 PM
int majorityElement(int* nums, int numsSize) {
    int count=0, candidate=0;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
        }
        if(candidate==nums[i]){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
}