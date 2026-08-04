// Last updated: 8/4/2026, 12:22:14 PM
int maximumPossibleSize(int* nums, int numsSize) {
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for(int i=0;i<numsSize;i++){
        int current = nums[i];
        while(top>=0&&stack[top]>current){
            current=current>stack[top]?current:stack[top];
            top--;
        }
        stack[++top] = current;
    }
    free(stack);
    return top+1;
}