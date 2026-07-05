#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int totalSize = nums1Size + nums2Size;
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) 
    {
        if (nums1[i] < nums2[j]) 
        {
            mergedArray[k++] = nums1[i++];
        } 
        else 
        {
            mergedArray[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) 
    {
        mergedArray[k++] = nums1[i++];
    }

    while (j < nums2Size) 
    {
        mergedArray[k++] = nums2[j++];
    }

    double median;
    if (totalSize % 2 == 0) 
    {
        median = (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
    } 
    else 
    {
        median = mergedArray[totalSize / 2];
    }

    free(mergedArray);
    
    return median;
}
