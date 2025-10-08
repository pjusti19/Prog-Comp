/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    
    int *runningSum = calloc(numsSize, sizeof(int));

    long long already_added = 0;

    for(int i = 0; i < numsSize; i++){
        runningSum[i] = nums[i] + already_added;
        already_added += nums[i];
    }

    *returnSize = numsSize;
    
    return runningSum;

}