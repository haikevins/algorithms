/*
    Each number appears twice.
    Only one number appears once.
    -> use XOR operation to find the single number.
    example: 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4
*/

int singleNumber(int* nums, int numsSize) 
{
    int result = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        result ^= nums[i];
    }
    return result;
}