int findKthLargest(int* nums, int numsSize, int k) 
{
    int count[20001] = {0};
    int offset = 10000;

    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i] + offset]++;
    }

    for (int value = 10000; value >= -10000; value--)
    {
        k -= count[value + offset];

        if (k <= 0)
        {
            return value;
        }
    }

    return -1;
}