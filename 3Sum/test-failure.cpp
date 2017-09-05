/**:
 * Author : JBCbobo
 * Descripe : Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * Date : 2017/9/5
 * Testing failure,speed too much time to debug.You should have the consider
 * the whole solution about the questions when you begian to design a program.
 * This is a lesson,do not look following program.
 */

//reference other program
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

//the idea is confuse,wang to find the rule of the problem.
int** threeSum(int* nums, int numsSize, int* returnSize) {
   
    int i,j,k,m = 0;
    int temp = 0;
    int **returnarray = (int **)malloc(sizeof(int *)*numsSize); 
    returnarray[m] = (int *)malloc(sizeof(int)*3);
    if(numsSize < 3)
    {
        *returnSize = 0;
        return returnarray;
    }
    quickSort(nums,0,numsSize-1) ;            
    for(i=0,m=0;i<numsSize;i++)
    {
        k=0;
        returnarray[m][k] = nums[i];
        for(j=0;j<numsSize;j++)
        {
            if(i==j) continue;
            temp = nums[i] + nums[j];
            //if(m!=0 && returnarray[m-1][1] - nums[j] == 0) continue;
            if(temp == nums[i]*2 || temp == nums[i]*1 || temp == nums[i]*(-1) \
		|| temp == 0 || temp == nums[i]/2 || temp == nums[i]/2*(-1))   //after testing,I think the rule can't solution the problem.
            {
                k++;
                returnarray[m][k] = nums[j];
            }
            if(k >= 2)
            {
                if((returnarray[m][0]+returnarray[m][1]+returnarray[m][2] == 0) \ 
			&& returnarray[m][0]<=returnarray[m][1]  )
                {
                    m++;
                    returnarray[m] = (int *)malloc(sizeof(int)*3);
                    break;
                }
                else
                {
                    k--;
                }
            }

        }

    }
    *returnSize = m;
    return returnarray;
    
}

