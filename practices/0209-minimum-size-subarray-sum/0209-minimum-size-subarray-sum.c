int minSubArrayLen(int target, int* nums, int numsSize) 
{
    int left = 0;
    int sum = 0;
    int minLen = numsSize + 1;

    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];

        while (sum >= target)
        {
            int currentLen = right - left + 1;

            if (currentLen < minLen)
            {
                minLen = currentLen;
            }

            sum -= nums[left];
            left++;
        }
    }

    if (minLen == numsSize + 1)
    {
        return 0;
    }

    return minLen;
}