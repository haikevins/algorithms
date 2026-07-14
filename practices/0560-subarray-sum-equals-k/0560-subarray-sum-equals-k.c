int subarraySum(int* nums, int numsSize, int k) 
{
    int count = 0;
    int* prefixSum = (int*)malloc((numsSize + 1) * sizeof(int));
    prefixSum[0] = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int start = 0; start < numsSize; start++) 
    {
        for (int end = start + 1; end <= numsSize; end++) 
        {
            if (prefixSum[end] - prefixSum[start] == k) 
            {
                count++;
            }
        }
    }

    free(prefixSum);
    return count;    
}