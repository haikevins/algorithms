/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int carry = 1;
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize;

    for (int i = digitsSize - 1; i >= 0; i--) 
    {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) 
    {
        result[0] = carry;
        (*returnSize)++;
        return result;
    } 
    else 
    {
        return result + 1;
    }    
}