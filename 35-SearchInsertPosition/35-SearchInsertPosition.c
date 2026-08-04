// Last updated: 8/4/2026, 12:25:41 PM
int searchInsert(int* nums, int numsSize, int target) {
    int left=0, right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return left;
}