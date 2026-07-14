


typedef struct 
{
    int* prefixSum;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) 
{
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->prefixSum = (int*)malloc((numsSize + 1) * sizeof(int));
    obj->prefixSum[0] = 0;
    
    for (int i = 0; i < numsSize; i++) 
    {
        obj->prefixSum[i + 1] = obj->prefixSum[i] + nums[i];
    }
    
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) 
{
    return obj->prefixSum[right + 1] - obj->prefixSum[left];
}

void numArrayFree(NumArray* obj) 
{
    free(obj->prefixSum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/