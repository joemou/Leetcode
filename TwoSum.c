/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,l;
    int n=numsSize;
    int* result = calloc(2,sizeof(int));

    for(i=0;i<n;i++){
        for(l=i+1;l<n;l++){
            if(nums[i]+nums[l]==target){
                result[0]=i;
                result[1]=l;
                break;
            }
        }
    }
    *returnSize=2;
    return result;

}