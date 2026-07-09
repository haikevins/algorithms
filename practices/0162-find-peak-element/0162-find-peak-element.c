int findPeakElement(int* nums, int numsSize) 
{
    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        /*
            The array is increasing;
            the peak is definitely located to the right.
        */
        if (nums[mid] < nums[mid + 1])
        {
            left = mid + 1;
        }
        /*
            The array is decreasing;
            the peak is definitely located to the left.
        */
        else
        {
            right = mid;
        }
    }

    return left;
}