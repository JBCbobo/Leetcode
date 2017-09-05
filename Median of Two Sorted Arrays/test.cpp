/*************************************************************************
	> File Name: test.cpp
	> Author:JBC
	> Mail: 
        > Descripe:The overall run time complexxity should be O(log(m+n))
	> Created Time: 2017年09月04日 星期一 14时38分33秒
 ************************************************************************/
 double findMedianSortedArrays(int* nums1,int nums1Size,int* nums2,int nums2Size)
 {
     int imin = 0;
     int imax = 0;
     int *temp = NULL;
     int halflen = 0;
     int num_temp = 0;
     int i,j;
     int maxleft;
     int minright;
     if(nums1Size > nums2Size) //ensure m<=n
     {
         temp = nums1;
         nums1 = nums2;
         nums2 = temp;

         num_temp = nums1Size;
         nums2Size = nums2Size;
         nums2Size = num_temp;
     }
     imax = num1Size;
     halflen = ( num2Size + num1Size + 1 )/ 2;
     while(imin<=imax)
     {
         i = ( imin + imax ) / 2;
         j = halflen - i;
         if(i<imax && nums2[j-1] > nums1[i]) //i is to small
         {
             imin = imin + 1;
         }
         else if(i>imin && nums2[j] < nums1[i - 1]) //i is to big
         {
             imax = imax - 1;
         }
         else //i is perfect
         {
             if(i == 0) maxleft = nums2[j-1];
             else if(j == 0) maxleft = nums1[i-1];
             else 
             {
                 maxleft = (nums2[j-1]>nums1[i-1]) ? nums2[j-1] : nums1[i -1];
             }
             if((nums1Size + nums2Size) % 2  == 1) return maxleft; // num1Size + num2Size is odd

             if(i == nums1Size) minright = nums2[j]
             else if(j == nums2Size) minright = nums1[i];
             else 
             {
                 minright = (nums2[j]<nums1[i]) ? nums2[j] : nums1[i];
             }
             return (maxleft + minright) / 2.0;  // num1Size + num2Size is even
         }
     }
     return 0;
 }

