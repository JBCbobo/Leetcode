/**
 * Descripe : Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * Date : 2017/9/5
 */
 public List<List<Integer>> threeSum(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> res = new LinkedList<>(); 
    for (int i = 0; i < num.length-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = num.length-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
}

/*----------------------------------------------------------------------------------------------------------*/
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int* nums,int first,int end){
    int temp,l,r;
    if(first>=end)return;
    temp=nums[first];
    l=first;r=end;
    while(l<r){
        while(l<r && nums[r]>=temp)r--;
        if(l<r)nums[l]=nums[r];
        while(l<r && nums[l]<=temp)l++;
        if(l<r)nums[r]=nums[l];
    }
    nums[l]=temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i,sum,top=-1,begin,end;
    int** res=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    if(numsSize<3){
        *returnSize=0;
        return res;
    }
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i++){
        if(nums[i]>0)break;
        if(i>0 && nums[i]==nums[i-1])continue;
        begin=i+1;end=numsSize-1;
        while(begin<end){
            sum=nums[i]+nums[begin]+nums[end];
            if(sum==0){
                top++;
	            res[top]=(int*)malloc(sizeof(int)*3);
	            res[top][0]=nums[i];res[top][1]=nums[begin];res[top][2]=nums[end];
	            begin++;end--;
	            while(begin<end && nums[begin]==nums[begin-1])begin++;
	            while(begin<end && nums[end]==nums[end+1])end--;
            }else if(sum>0) end--;
            else begin++;
        }
    }
    *returnSize=top+1;
    return res;
}
/*----------------------------------------------------------------------------------------------------------*/



