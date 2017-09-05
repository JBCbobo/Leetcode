/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *return_array=NULL;
    return_array = (int *)malloc(sizeof(int)*2);
    for(i = 0;i<numsSize;i++)
    {
        for(j = i+1;j<numsSize;j++)        
        {
            if(*(nums+i)==target - *(nums+j))
            {
                *return_array = i;
                *(return_array+1) = j;
            }
        }
    }
    return return_array;
    
}