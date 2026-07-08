void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize;
    int* temp = (int*)malloc(k * sizeof(int));
    
    // Copy the last k elements to a temporary array
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[numsSize - k + i];
    }
    
    // Shift the remaining elements to the right
    for (int i = numsSize - 1; i >= k; i--)
    {
        nums[i] = nums[i - k];
    }
    
    // Copy the elements from the temporary array to the beginning
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
    
    free(temp);
}