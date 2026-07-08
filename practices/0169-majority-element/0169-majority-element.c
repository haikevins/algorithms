/*
    Majority Element appears more than n/2 times in the array
    -> meaning that its number of occurrences is greater than 
       the total number of occurrences of all the remaining elements.
*/
int majorityElement(int* nums, int numsSize) 
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}