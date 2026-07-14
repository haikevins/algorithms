#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) 
{
    int offset = 10000;
    int range = 20001;

    int* count = (int*)calloc(range, sizeof(int));

    // Count frequency of each number
    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i] + offset]++;
    }

    // bucketSize[f] = how many numbers appear f times
    int* bucketSize = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < range; i++)
    {
        if (count[i] > 0)
        {
            bucketSize[count[i]]++;
        }
    }

    // Create buckets
    int** buckets = (int**)calloc(numsSize + 1, sizeof(int*));

    for (int freq = 1; freq <= numsSize; freq++)
    {
        if (bucketSize[freq] > 0)
        {
            buckets[freq] = (int*)malloc(bucketSize[freq] * sizeof(int));
        }
    }

    int* index = (int*)calloc(numsSize + 1, sizeof(int));

    // Put numbers into buckets based on frequency
    for (int i = 0; i < range; i++)
    {
        if (count[i] > 0)
        {
            int num = i - offset;
            int freq = count[i];

            buckets[freq][index[freq]] = num;
            index[freq]++;
        }
    }

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    int resultIndex = 0;

    // Get numbers from highest frequency to lowest
    for (int freq = numsSize; freq >= 1 && resultIndex < k; freq--)
    {
        for (int j = 0; j < index[freq] && resultIndex < k; j++)
        {
            result[resultIndex] = buckets[freq][j];
            resultIndex++;
        }
    }

    // Free memory
    for (int freq = 1; freq <= numsSize; freq++)
    {
        if (buckets[freq] != NULL)
        {
            free(buckets[freq]);
        }
    }

    free(buckets);
    free(bucketSize);
    free(index);
    free(count);

    return result;
}